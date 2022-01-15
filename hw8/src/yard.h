#ifndef YARD_H
#define YARD_H

#include <vector>

#include "cat.h"
#include "dog.h"
#include "pet.h"


class Yard {
public:
    Yard() = default;

    ~Yard() {
        deletePets();
    }

    Yard(const Yard &yard) {
        copyPets(yard._pets);
    }

    Yard& operator=(const Yard &yard) {
        copyPets(yard._pets);
        return *this;
    }

    void addPet(Pet * pet) {
        _pets.push_back(pet);
    }


    template<typename Condition>
    std::vector<Pet *> getPetWithCondition(Condition cond) {
        std::vector<Pet *> pets_in_cond;
        for (Pet * pet : _pets) {
            if (cond(pet)) {
                pets_in_cond.push_back(pet);
            }
        }
        return pets_in_cond;
    }

private:
    std::vector<Pet *> _pets;

    void deletePets() {
        for(int i = 0; i < _pets.size(); i++) {
            if(_pets[i] != nullptr) {
                delete _pets[i];
            }
        }
    }

    void copyPets(std::vector<Pet *> pets) {
        std::vector<Pet *> newPets;
        for(int i = 0; i < pets.size(); i++) {
            if(pets[i]->kind() == "CAT") {
                newPets.push_back(new Cat(pets[i]->name(), pets[i]->weight()));
            } else {
                newPets.push_back(new Dog(pets[i]->name(), pets[i]->weight()));
            }
        }

        deletePets();
        _pets = newPets;
    }
};


#endif /* end of include guard: YARD_H */