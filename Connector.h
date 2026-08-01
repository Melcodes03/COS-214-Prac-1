#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>
#include <string>

// Product declares the interface every concrete connector must implement.
class Connector {
protected:
    std::string source;

public:
    Connector(std::string source);

    std::string getSource() const;

    // Primitive operation each concrete connector must supply.
    virtual std::vector<std::string> extract() = 0; //pure virtual function

    virtual ~Connector();
};

#endif