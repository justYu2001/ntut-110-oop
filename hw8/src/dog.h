#ifndef DOG_H
#define DOG_H

#include <stdexcept>
#include <string>

#include "pet.h"

using std::string;

class Dog : public Pet {
public:

  /*  add and modify your code from assignment 8  */

    Dog(string name, double weight): Pet("DOG", name, weight) {
        if(weight < 10 || weight > 50) {
            throw std::range_error("weight must be over 10 and under 50");
        }

        _amount++;
    }

    ~Dog() {
        _amount--;
    }

    Dog(const Dog &dog): Pet(dog.kind(), dog.name(), dog.weight()) {
        _amount++;
    }

    void feed() override {
        double newWeight = this->weight() + 0.8;
        this->setWeight(newWeight);

        if(newWeight > 50) {
            throw std::out_of_range("weight over 50");
        }
    }

    static int amount() {
        return _amount;
    }

private:
    static int _amount;

};

int Dog::_amount = 0;


#endif /* end of include guard: DOG_H */
