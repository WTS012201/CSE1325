#include "student.h"
#include "parent.h"

Parent::Parent(std::string name, std::string email) : Person{name, email}{}

Parent::Parent(std::istream& ist) : Person{ist} {}

void Parent::add_student(Student& student){
    _students.push_back(&student);
}

std::string Parent::full_info(){
    std::string s;
    for(Student* st : *this)
        s += st->to_string() + ", ";
    return Person::full_info() + " - Students: " + s;
}
void Parent::save(std::ostream& ost){
    Person::save(ost);
}