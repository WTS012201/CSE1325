#include "student.h"
#include "parent.h"

Parent::Parent(std::string name, std::string email) : Person{name, email}{}

void Parent::add_student(Student& student){
    _students.push_back(&student);
}

int Parent::students(){
    return _students.size();
}

Student& Parent::student(int index){
    if(index < 0 || index >= students())
        throw std::out_of_range("out of range");
    return *_students.at(index);
}

std::string Parent::full_info(){
    std::string s;
    for(int i = 0; i < students() - 1; i++)
        s += student(i).to_string() + ", ";
    if(students() > 0)
        s += student(students() - 1).to_string();
    return Person::full_info() + " - Students: " + s;
}