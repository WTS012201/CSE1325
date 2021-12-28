#ifndef __COURSE_H
#define __COURSE_H

#include "subject.h"

class Course {
    private:
        Subject subject;
        int grade;
    public:
        Course(Subject subject, int grade);
        Course(std::istream& ist);
        void save(std::ostream& ost);
        friend std::ostream& operator<<(std::ostream& ost, const Course course);
        std::string to_string();
        std::string full_info();
};

#endif