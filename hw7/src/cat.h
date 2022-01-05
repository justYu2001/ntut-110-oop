#ifndef CAT_H
#define CAT_H

#include <string>

#include "pet.h"

using std::string;

class Cat: public Pet {
public:
    Cat() {
        _name = "";
        _weight = 0;
    }

    Cat(string name, double weight) {
        _name = name;

        if(weight < 2 || weight > 6) {
            throw std::range_error("weight must be over 2 and under 6");
        }

        _weight = weight;
    }

    void feed() override {
        _weight += 0.2;

        if(_weight > 6) {
            throw std::out_of_range("weight over 6");
        }
    }
};

#endif