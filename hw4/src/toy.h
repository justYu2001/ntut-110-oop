#ifndef TOY_H
#define TOY_H

#include <string>

using std::string;

class Toy {
public:

    Toy() {}

    // constructor with parameter
    Toy(string name) { 
        _name = name;
    }

    // get the name of the toy
    string getName() const { 
        return this->_name;
    }

private:
    string _name;
};

#endif