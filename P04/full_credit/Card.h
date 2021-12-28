#ifndef __CARD_H
#define __CARD_H

#include <string>

class Card{
    private:
        std::string _question;
        std::string _answer;
    public:
        Card(std::string question, std::string answer);
        std::string attempt(std::string response);
        friend std::ostream& operator<<(std::ostream& ost, Card& m);
};

#endif