#include "CheckpointManager.h"

void CheckpointManager::save(RunCheckpoint* cp) {
    history.push_back(cp);
}

RunCheckpoint* CheckpointManager::undo() {
    if (history.empty()) {
        return nullptr;
    }
    RunCheckpoint* cp = history.back();
    history.pop_back();
    return cp;
}

CheckpointManager::~CheckpointManager() {
    history.clear();
}