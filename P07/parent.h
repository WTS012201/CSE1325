class Student;

#ifndef __PARENT_H
#define __PARENT_H

#include "person.h"

class Parent : public Person{
    protected:
        std::vector<Student*> _students;
    public:
        virtual void save(std::ostream& ost);
        Parent(std::string name, std::string email);
        Parent(std::istream& ist);
        void add_student(Student& student);
        int students();
        Student& student(int index);
        std::string full_info() override;
};

#endif