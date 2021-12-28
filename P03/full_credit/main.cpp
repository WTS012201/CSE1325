#include "fraction.h"
#include <iostream>
int main(){

    Fraction frac1, frac2, tempFrac;

    std::cout << "Enter fraction 1: ";
    std::cin >> frac1;
    std::cout << "Enter fraction 2: ";
    std::cin >> frac2;

    tempFrac = Fraction{1,1}/frac1;
    std::cout << "\nInverse of fraction 1: " << tempFrac << std::endl;

    tempFrac = Fraction{1,1}/frac2;
    std::cout << "Inverse of fraction 2: " << tempFrac << std::endl;

    tempFrac = frac1 + frac2;
    std::cout << "fraction 1 + fraction 2: " << tempFrac << std::endl;

    tempFrac = frac1 - frac2;
    std::cout << "fraction 1 - fraction 2: " << tempFrac << std::endl;

    tempFrac = frac1 * frac2;
    std::cout << "fraction 1 * fraction 2: " << tempFrac << std::endl;

    tempFrac = frac1 / frac2;
    std::cout << "fraction 1 / fraction 2: " << tempFrac << std::endl;
}