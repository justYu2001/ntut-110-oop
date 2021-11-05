#include <string>

using std::string;

class Cat {
public:

    Cat(string name, double weight) {
        _name = name;
        _weight = weight;
        _toyAmount = 0;
        _capacityOfToyCollections = 2;
        _toyCollections = new string[_capacityOfToyCollections];
    }

    ~Cat() {
        delete [] _toyCollections;
    }

    string getName() {
        return _name;
    }

    double getWeight() {
        return _weight;
    }

    void addNewToy(string toyName) {
        if(_toyAmount == _capacityOfToyCollections) {
            reserveToyCollections();
        }
        _toyCollections[_toyAmount++] = toyName;
    }

    string getToy(int index) {
        return _toyCollections[index];
    }

private:
    string _name;
    double _weight;
    string * _toyCollections;
    int _toyAmount;
    int _capacityOfToyCollections;

    void reserveToyCollections() {
        int newCapacity = _toyAmount * 2;
        string *newToyCollections = new string[newCapacity];
        for(int i = 0; i < _toyAmount; i++) {
            newToyCollections[i] = _toyCollections[i];
            _toyCollections[i].clear();
        }
        _capacityOfToyCollections = newCapacity;
        if(_toyCollections) {
            delete [] _toyCollections;
        }
        _toyCollections = nullptr;
        _toyCollections = newToyCollections;
    }
};
