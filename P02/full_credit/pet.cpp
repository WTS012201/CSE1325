#include "pet.h"
#include <string>
#include <vector>

Pet::Pet(std::string name, double age, Type type) : _name{name}, _age{age}, _type{type}{}

std::string Pet::to_string(){
    std::vector<std::string> types = {"Cat", "Dog", "Hamster", "Parakeet"};
    return _name + " is a " + types[_type] + " age " + std::to_string(_age);
}

