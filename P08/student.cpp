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

int Student::parents(){
    return _parents.size();
}

Parent& Student::parent(int index){
    if(index < 0 || index >= parents())
        throw std::out_of_range("out of range");
    return *_parents.at(index);
}
std::string Student::full_info(){
    std::string s;
    for(int i = 0; i < parents() - 1; i++)
        s += parent(i).to_string() + ", ";
    if(parents() > 0)
        s += parent(parents() - 1).to_string();
    return Person::full_info() + " grade: " + std::to_string(_grade) + " - Parents: " + s;
}
void Student::save(std::ostream& ost){
    Person::save(ost);
    ost << _grade << std::endl;
}