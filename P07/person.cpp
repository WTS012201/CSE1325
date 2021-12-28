#include "person.h"

Person::Person(std::string name, std::string email) : _name{name}, _email{email}{}
Person::Person(std::istream& ist){
    ist >> _name >> _email;
    ist.ignore(32767, '\n');
}
std::string Person::to_string(){
    return _name;
}
std::string Person::full_info(){
    return _name + " (" + _email + ")";
}
std::ostream& operator<<(std::ostream& ost, const Person person){
    ost << person._name;
    return ost;
}
void Person::save(std::ostream& ost){
    ost << _name << std::endl;
    ost << _email << std::endl;
}