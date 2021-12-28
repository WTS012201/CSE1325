#ifndef __GRADE_H
#define __GRADE_H

#include <iostream>

enum class Grade {
    A, B, C, D, F, I, X
};
std::ostream& operator<<(std::ostream& ost, const Grade grade);
std::string load_semester(std::istream& ist);

#endif