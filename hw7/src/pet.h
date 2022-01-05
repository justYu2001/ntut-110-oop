#ifndef PET_H
#define PET_H

#include <string>

using std::string;

class Pet {
protected:
    string _name;
    double _weight;

public:
    virtual ~Pet() {}

    string name() const {
        return _name;
    }

    double weight() const {
        return _weight;
    }

    virtual void feed() = 0;
};

#endif