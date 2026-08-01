#include "Pipeline.h"
#include <iostream>

Pipeline::Pipeline(ConnectorFactory* factory)
    : factory(factory), stage(0) {}

void Pipeline::addStep(Transformation* step) {
    steps.push_back(step);
}

// Template method: fixes the algorithm's skeleton. NOT virtual, so no
// subclass can change the order (or omission) of these four stages.
void Pipeline::run() {
    connect();
    extract();
    transform();
    load();
}

// Concrete step, shared by every subclass.
void Pipeline::connect() {
    Connector* connector = factory->createConnector();
    std::cout << "Connecting to " << connector->getSource() << std::endl;
    stage = 1;
    delete connector;
}

// Concrete step, shared by every subclass.
void Pipeline::transform() {
    for (Transformation* step : steps) {
        records = step->apply(records);
    }
    stage = 3;
}

// Memento hooks (Originator side)
RunCheckpoint* Pipeline::createCheckpoint() {
    return new RunCheckpoint(stage, records);
}

void Pipeline::restore(RunCheckpoint* checkpoint) {
    stage = checkpoint->getStage();
    records = checkpoint->getRecords();
}

Pipeline::~Pipeline() {
    delete factory;
    for (Transformation* step : steps) {
        delete step;
    }
}