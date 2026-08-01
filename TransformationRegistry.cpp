#include "TransformationRegistry.h"

void TransformationRegistry::registerStep(std::string key, Transformation* prototype) {
    std::map<std::string, Transformation*>::iterator it = prototypes.find(key);
    if (it != prototypes.end()) {
        //replacing an existing prototype under this key -> free the old one first
        delete it->second;
        prototypes.erase(it);
    }
    prototypes[key] = prototype;
}

Transformation* TransformationRegistry::create(std::string key) {
    std::map<std::string, Transformation*>::iterator it = prototypes.find(key);
    if (it == prototypes.end()) {
        return nullptr;
    }
    return it->second->clone();
}

TransformationRegistry::~TransformationRegistry() {
    for (std::map<std::string, Transformation*>::iterator it = prototypes.begin();
         it != prototypes.end(); ++it) {
        delete it->second;
    }
    prototypes.clear();
}