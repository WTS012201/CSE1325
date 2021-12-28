#ifndef __HINTCARD_H
#define __HINTCARD_H

#include "Card.h"
#include <string>

class Hintcard : public Card{
    private:
        std::string _hint;
    public:
        Hintcard(std::string question, std::string answer, std::string hint);
        std::string attempt(std::string response) override;
};

#endif