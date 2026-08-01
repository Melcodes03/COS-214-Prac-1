#include "Transformation.h"

Transformation::Transformation(std::string name) : name(name) {}

std::string Transformation::getName() const {
    return name;
}

Transformation::~Transformation() {}

//DeduplicateStep

DeduplicateStep::DeduplicateStep() : Transformation("dedup") {}

Transformation* DeduplicateStep::clone() {
    return new DeduplicateStep();
}

std::vector<std::string> DeduplicateStep::apply(std::vector<std::string> records) {
    std::vector<std::string> result;
    for (size_t i = 0; i < records.size(); ++i) {
        //only compare to the previous kept record 
        if (result.empty() || result.back() != records[i]) {
            result.push_back(records[i]); //removes CONSECUTIVE duplicates
        }
    }
    return result;
}

//AggregateByRegionStep

AggregateByRegionStep::AggregateByRegionStep() : Transformation("aggregate") {}

Transformation* AggregateByRegionStep::clone() {
    return new AggregateByRegionStep();
}

std::vector<std::string> AggregateByRegionStep::apply(std::vector<std::string> records) {
    std::vector<std::string> result;
    result.push_back("COUNT=" + std::to_string(records.size()));
    return result;
}