#include "pet.h"
#include <string>
#include <vector>

const int human_lifespan = 80;

Pet::Pet(std::string name, double age, Type type) : _name{name}, _age{age}, _type{type}{}

double Pet::human_years(){
    return _age * human_lifespan / pet_lifespan[_type];
}

std::string Pet::to_string(){
    std::vector<std::string> types = {"Cat", "Dog", "Hamster", "Parakeet"};
    return _name + " is a " + types[_type] + " age " + std::to_string(_age) + " or " + std::to_string(human_years()) + " in human-equivalent years";
}
