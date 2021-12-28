#include <iostream>
#include "pet.h"
#include <vector>
#include <algorithm>
/*
bool comparator(double i, double j){
    return (i<j);
}
*/
int main(){
    std::vector<Pet> petList = {{"Billy", 12, DOG},{"Sammy", 5, CAT},
    {"Hammy", 2.5, HAMSTER},{"Wammy", 13, PARAKEET}};
    std::sort (petList.begin(), petList.end());
    for(int i=0; i < petList.size(); i++){
        std::cout << petList[i].to_string() << std::endl;
    }
}