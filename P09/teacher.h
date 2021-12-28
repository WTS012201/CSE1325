#ifndef __TEACHER_H
#define __TEACHER_H

#include "person.h"

class Teacher : public Person {
    public:
        Teacher(std::string name, std::string email);
        Teacher(std::istream& ist);
        std::string full_info() override;
        virtual void save(std::ostream& ost);
};

#endif