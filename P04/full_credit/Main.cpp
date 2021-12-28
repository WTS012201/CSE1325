#include <iostream>
#include "Deck.h"

void printOptions(Deck* myDeck, std::vector<std::string> options){
    std::cout << std::endl;
    for(int i = 0; i < options.size(); i++){
        std::cout << std::to_string(i) + ") " + options.at(i) << std::endl;
    }
    std::cout << std::endl;
}

int main(){
    Deck* myDeck = (Deck*)malloc(sizeof(Deck));
    int in;

    myDeck -> add_card("Reuse and extension of fields and method implementations from another class? ","Inheritance");
    myDeck -> add_card("Bundling data and code into a restricted container? ","Encapsulation");
    myDeck -> add_card("A data type consisting of a fixed set of constant values called enumerators? ","Enumerated type");
    myDeck -> add_card("A template encapsulating data and code that manipulates it? ","Class");
    myDeck -> add_card("An encapsulated bundle of data and code? ","Instance");
    myDeck -> add_card("An instance of a class containing a set of encapsulated data and associated methods? ","Object");
    myDeck -> add_card("A special class member that cleans up when an object is deleted? ","Destructor");
    myDeck -> add_card("A class or a function that is granted access to its friend class’ private members? ","Friend");
    myDeck -> add_card("The class from which members are inherited? ","Base Class");
    myDeck -> add_card("The class inheriting members? ","Derived Class");

    myDeck -> add_false_answer("Method");
    myDeck -> add_false_answer("Variable");
    myDeck -> add_false_answer("Operator");

    std::vector<std::string> options = myDeck -> options();
    std::cout << "Select the number of the term for each definition (-1 to exit)\n";
    
    while(true){
        Card c = myDeck -> deal();
        
        printOptions(myDeck, options);
        std::cout << c;
        std::cin >> in;
        if(in<0){
            break;
        }
        else{
            std::cout << c.attempt(options.at(in));
        }
    }
    return 0;
}