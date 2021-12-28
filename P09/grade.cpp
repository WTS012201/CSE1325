#include "grade.h"

std::ostream& operator<<(std::ostream& ost, const Grade grade){
    std::string s;
    switch(grade){
        case Grade::A: s = "A"; break;
        case Grade::B: s = "B"; break;
        case Grade::C: s = "C"; break;
        case Grade::D: s = "D"; break;
        case Grade::F: s = "F"; break;
        case Grade::I: s = "I"; break;
        case Grade::X: s = "X"; break;
    }
    ost << s;
    return ost;
}
std::string load_grade(std::istream& ist){
    std::string grade;
    std::getline(ist, grade);
    return grade;
}