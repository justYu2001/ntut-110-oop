#ifndef CAT_H
#define CAT_H

#include <string>
#include <vector>

#include "./toy.h"

using std::string;
using std::vector;

class Cat {
public:

    Cat() {}

    Cat(string name, double weight) {
        init(name, weight);
    }

    Cat(Cat const & other) {
        init(other._name, other._weight);
        this->_toyCollections = other._toyCollections;
    }

    ~Cat() {}

    string getName() {
        return _name;
    }

    double getWeight() {
        return _weight;
    }

    void addNewToy(Toy const & toyName) {
        _toyCollections.push_back(toyName);
    }

    Toy getToy(int index) const {
        if(index >= _toyCollections.size()) {
            throw string("error");
        }
        return _toyCollections[index];
    }

    Cat & operator = (Cat const & other) { 
        this->_name = other._name;
        this->_weight = other._weight;
        this->_toyCollections = other._toyCollections;
        return *this;
    }

    bool isHeavierThan(Cat const & other) const { 
        return this->_weight > other._weight;
    }

private:
    string _name;
    double _weight;
    vector<Toy> _toyCollections;

    void init(string name, double weight) {
        if(name == "") {
            throw string("error");
        }
        if(weight < 10 || weight > 50) {
            throw string("error");
        }
        _name = name;
        _weight = weight;
        _toyCollections.reserve(10);
    }
};

#endif