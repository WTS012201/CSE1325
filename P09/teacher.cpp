#include "teacher.h"

Teacher::Teacher(std::string name, std::string email) : Person{name, email}{}

Teacher::Teacher(std::istream& ist) : Person{ist}{}

std::string Teacher::full_info(){
    return Person::full_info();
}

void Teacher::save(std::ostream& ost){
    Person::save(ost);
}