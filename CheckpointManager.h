#ifndef CHECKPOINT_MANAGER_H
#define CHECKPOINT_MANAGER_H

#include <vector>
#include "RunCheckpoint.h"

//Caretaker: stores mementos, never reads their internals (narrow interface only).
//Aggregation, not composition NB! does NOT own the RunCheckpoints it holds,
// o it must not delete them (see corrected UML message).
class CheckpointManager {
private:
    std::vector<RunCheckpoint*> history;
public:
    void save(RunCheckpoint* cp);
    RunCheckpoint* undo();
    ~CheckpointManager();
};

#endif