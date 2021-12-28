#include "Card.h"
#include <string>
std::string to_upper(std::string s){
    for(int i=0; i<s.length(); i++){
        s[i] = std::toupper(s[i]);
    }
    return s;
}

Card::Card(std::string question, std::string answer) : _question{question}, _answer{answer} {}

std::string Card::attempt(std::string response){
    return (to_upper(_answer)).compare(to_upper(response)) ? "\nX - correct answer was " + to_upper(_answer) + "\n": "\nCorrect!\n";
}

std::ostream& operator<<(std::ostream& ost, Card& m){
    ost << m._question;
    return ost;
}