#include "Deck.h"
#include <algorithm>
#include <iostream>
void Deck::add_card(std::string question, std::string answer){
    _cards.push_back(Card{question, answer});
    _options.push_back(answer);
    _next_card = _cards.size();
}

void Deck::add_false_answer(std::string false_answer){
    _options.push_back(false_answer);
}

std::vector<std::string> Deck::options(){
    std::sort(_options.begin(), _options.end());
    return _options;
}

Card Deck::deal(){
    if(!_cards.size()){
        throw std::runtime_error{"No cards have been added"};
    }
    if(_next_card == _cards.size()){
        std::random_shuffle(_cards.begin(), _cards.end());
        std::cout << "\nSHUFFLE\n";
    }
    if(_next_card > 0 ){
        _next_card--;
    }
    else{
        _next_card = _cards.size();
        return deal();
    }
    return _cards.at(_next_card);
}