#include <iostream>
#include "ConnectorFactory.h"
#include "PostgresFactory.h"
#include "Transformation.h"
#include "TransformationRegistry.h"
#include "Pipeline.h"
#include "BatchPipeline.h"
#include "RunCheckpoint.h"
#include "CheckpointManager.h"

int main() {
    // 1. Registry with pre-configured prototypes
    TransformationRegistry registry;
    registry.registerStep("dedup", new DeduplicateStep());
    registry.registerStep("aggregate", new AggregateByRegionStep());

    // 2. BatchPipeline wired to a PostgresFactory (Pipeline takes ownership of factory)
    ConnectorFactory* factory = new PostgresFactory();
    Pipeline* pipeline = new BatchPipeline(factory);

    // 3. Add cloned steps from the registry -- never construct steps directly
    pipeline->addStep(registry.create("dedup"));
    pipeline->addStep(registry.create("aggregate"));

    // 4. CheckpointManager (Caretaker)
    CheckpointManager manager;

    // 5. Run the pipeline, then checkpoint and save its state
    pipeline->run();
    RunCheckpoint* checkpoint = pipeline->createCheckpoint();
    manager.save(checkpoint);

    // 6. Clean up everything we own.
    // CheckpointManager is an aggregation of RunCheckpoint (per the corrected UML) --
    // it does NOT delete what it holds, so we must delete the checkpoint ourselves.
    delete checkpoint;
    // Pipeline's destructor deletes the factory and every owned Transformation step.
    delete pipeline;

    return 0;
}