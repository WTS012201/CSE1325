#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade) :
Person{name, email}, _grade{grade}{}

Student::Student(std::istream& ist) : Person{ist}{
    ist >> _grade;
    ist.ignore(32767, '\n');
}
void Student::add_parent(Parent& parent){
    _parents.push_back(&parent);
}
std::string Student::full_info(){
    std::string s;
    for(Parent* p : *this)
        s += p->to_string() + ", ";
    return Person::full_info() + " grade: " + std::to_string(_grade) + " - Parents: " + s;
}
void Student::save(std::ostream& ost){
    Person::save(ost);
    ost << _grade << std::endl;
}