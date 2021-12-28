#include <iostream>

int main(){
    std::string str = "";
    std::cout << "What's your name? ";
    std::getline(std::cin, str);
    std::cout << "Hello, " << str << "!\n";
    return 0;
}
