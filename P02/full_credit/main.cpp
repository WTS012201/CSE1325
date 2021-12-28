#include <iostream>
#include "pet.h"
#include <vector>
int main(){
    std::vector<Pet> petList = {{"Billy", 12, DOG},{"Sammy", 5, CAT},
    {"Hammy", 2.5, HAMSTER},{"Wammy", 13, PARAKEET}};
    for(int i=0; i < petList.size(); i++){
        std::cout << petList[i].to_string() << std::endl;
    }
}