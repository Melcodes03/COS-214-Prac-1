#ifndef RUNCHECKPOINT_H
#define RUNCHECKPOINT_H

#include <vector>
#include <string>

// Memento: stores a snapshot of Pipeline state. Only Pipeline (the
// Originator) should construct one or inspect its full contents;
// CheckpointManager (the Caretaker) only stores and returns it,
// treating it as opaque.
class RunCheckpoint {
private:
    int stage;
    std::vector<std::string> records;

public:
    RunCheckpoint(int stage, std::vector<std::string> records);

    int getStage() const;
    std::vector<std::string> getRecords() const;
};

#endif