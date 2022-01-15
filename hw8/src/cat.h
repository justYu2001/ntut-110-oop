#ifndef CAT_H
#define CAT_H

#include <stdexcept>
#include <string>

#include "pet.h"

using std::string;

class Cat : public Pet {
public:

  /*  add and modify your code from assignment 8  */

    Cat(string name, double weight): Pet("CAT", name, weight) {
        if(weight < 2 || weight > 6) {
            throw std::range_error("weight must be over 2 and under 6");
        }

        _amount++;
    }

    ~Cat() {
        _amount--;
    }

    Cat(const Cat &cat): Pet(cat.kind(), cat.name(), cat.weight()) {
        _amount++;
    }

    void feed() override {
        double newWeight = this->weight() + 0.2;
        this->setWeight(newWeight);

        if(newWeight > 6) {
            throw std::out_of_range("weight over 6");
        }
    }

    static int amount() {
        return _amount;
    }

private:
    static int _amount;

};

int Cat::_amount = 0;


#endif /* end of include guard: CAT_H */