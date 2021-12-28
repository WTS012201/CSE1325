class Parent;

#ifndef __STUDENT_H
#define __STUDENT_H

#include "person.h"

class Student : public Person{
    protected:
        int _grade;
        std::vector<Parent*> _parents;
    public:
        Student(std::string name, std::string email, int grade);
        void add_parent(Parent& parent);
        int parents();
        Parent& parent(int index);
        std::string full_info() override;
};
#endif