#ifndef TRANSFORMATION_REGISTRY_H
#define TRANSFORMATION_REGISTRY_H

#include <map>
#include <string>
#include "Transformation.h"

//owns prototypes and hands out clones on request
class TransformationRegistry {
private:
    std::map<std::string, Transformation*> prototypes;
public:
    void registerStep(std::string key, Transformation* prototype);
    Transformation* create(std::string key);
    ~TransformationRegistry();
};

#endif