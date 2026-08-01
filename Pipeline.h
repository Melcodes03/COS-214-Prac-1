#ifndef PIPELINE_H
#define PIPELINE_H

#include <vector>
#include <string>
#include "ConnectorFactory.h"
#include "Transformation.h"
#include "RunCheckpoint.h"

// AbstractClass: fixes the pipeline lifecycle (run()) while leaving
// extract()/load() as primitive operations for subclasses to define.
class Pipeline {
protected:
    ConnectorFactory* factory;
    std::vector<Transformation*> steps;
    int stage;
    std::vector<std::string> records;

public:
    Pipeline(ConnectorFactory* factory);

    void addStep(Transformation* step);

    // Template method — fixed algorithm skeleton. NOT virtual.
    void run();

    // Memento hooks (Task 4 — Originator side)
    RunCheckpoint* createCheckpoint();
    void restore(RunCheckpoint* checkpoint);

    virtual ~Pipeline();

protected:
    // Concrete step — shared by all subclasses.
    void connect();

    // Primitive operation — each concrete pipeline defines this.
    virtual void extract() = 0;

    // Concrete step — shared by all subclasses.
    void transform();

    // Primitive operation — each concrete pipeline defines this.
    virtual void load() = 0;
};

#endif