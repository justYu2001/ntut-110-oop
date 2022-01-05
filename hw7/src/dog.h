#ifndef DOG_H
#define DOG_H

#include <string>

#include "pet.h"

using std::string;

class Dog: public Pet {
public:
    Dog() {
        _name = "";
        _weight = 0;
    }

    Dog(string name, double weight) {
        _name = name;

        if(weight < 10 || weight > 50) {
            throw std::range_error("weight must be over 10 and under 50");
        }

        _weight = weight;
    }

    void feed() override {
        _weight += 0.8;

        if(_weight > 50) {
            throw std::out_of_range("weight over 50");
        }
    }
};

#endif