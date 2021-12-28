#ifndef __SECTION_H
#define __SECTION_H

#include "semester.h"
#include "course.h"
class Section {
    private:
       Course course;
       Semester semester;
       int year;
    public:
        Section(Course _course, Semester _semester, int _year);
        Section(std::istream& ist);
        void save(std::ostream& ost);
        friend std::ostream& operator<<(std::ostream& ost, const Section section);
        std::string to_string();
        std::string full_info();
};

#endif