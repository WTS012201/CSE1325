#ifndef __PET_H
#define __PET_H

#include <string>
#include <vector>

enum Type {CAT, DOG, HAMSTER, PARAKEET};
const std::vector<int> pet_lifespan = {16, 13, 3, 12};

class Pet{
    std::string _name;
    double _age, _humanAge;
    Type _type;
    public:
        Pet(std::string name, double age, Type type);
        std::string to_string();
        double human_years();
        bool operator< (const Pet &o) const {
        return _humanAge < o._humanAge;
    }
};

#endif
