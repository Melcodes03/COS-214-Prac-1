#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <string>
#include <vector>

//prototype (product)
class Transformation {
protected:
    std::string name;
public:
    Transformation(std::string name);
    virtual Transformation* clone() = 0;
    virtual std::vector<std::string> apply(std::vector<std::string> records) = 0;
    std::string getName() const;
    virtual ~Transformation();
};

//concrete prototype
class DeduplicateStep : public Transformation {
public:
    DeduplicateStep();
    Transformation* clone() override;
    std::vector<std::string> apply(std::vector<std::string> records) override;
};

//concrete prototype
class AggregateByRegionStep : public Transformation {
public:
    AggregateByRegionStep();
    Transformation* clone() override;
    std::vector<std::string> apply(std::vector<std::string> records) override;
};

#endif