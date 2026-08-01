#ifndef CONNECTORFACTORY_H
#define CONNECTORFACTORY_H

#include "Connector.h"

// Creator declares the factory method. Never names a concrete Connector.
class ConnectorFactory {
public:
    virtual Connector* createConnector() = 0;
    virtual ~ConnectorFactory();
};

#endif