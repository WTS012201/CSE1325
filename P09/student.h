class Parent;

#ifndef __STUDENT_H
#define __STUDENT_H

#include "person.h"

class Student : public Person{
    protected:
        int _grade;
        typedef std::vector<Parent*> Parents;
        Parents _parents;
    public:
        virtual void save(std::ostream& ost);
        Student(std::string name, std::string email, int grade);
        Student(std::istream& ist);
        void add_parent(Parent& parent);
        std::string full_info() override;
        typedef Parents::iterator iterator;
        typedef Parents::const_iterator const_iterator;
        iterator begin() {return _parents.begin();}
        iterator end() {return _parents.end();}
};
#endif