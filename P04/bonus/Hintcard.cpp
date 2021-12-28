#include "Hintcard.h"
#include <string>
#include <iostream>
std::string to_upper(std::string s);

Hintcard::Hintcard(std::string question, std::string answer, std::string hint) : Card{question, answer}, _hint{hint} {std::cout << "HINT\n";}

std::string Hintcard::attempt(std::string response){
    return (to_upper(_answer)).compare(to_upper(response)) ? "\nX - Hint: " + _hint + "\n": "\nCorrect!\n";
}