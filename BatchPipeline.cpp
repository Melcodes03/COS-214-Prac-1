#include "BatchPipeline.h"
#include <iostream>

BatchPipeline::BatchPipeline(ConnectorFactory* factory) : Pipeline(factory) {}

// Primitive operation: batch-specific extraction.
void BatchPipeline::extract() {
    Connector* connector = factory->createConnector();
    records = connector->extract();
    std::cout << "Batch extract: " << records.size() << " records" << std::endl;
    stage = 2;
    delete connector;
}

// Primitive operation: batch-specific load.
void BatchPipeline::load() {
    std::cout << "Batch load: " << records.size() << " records written" << std::endl;
    stage = 4;
}