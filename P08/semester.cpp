#include "semester.h"

std::ostream& operator<<(std::ostream& ost, const Semester semester){
    std::string s;
    switch(semester){
        case Semester::SPRING: s = "spring"; break;
        case Semester::SUMMER: s = "summer"; break;
        case Semester::FALL: s = "fall"; break;
    }
    ost << s;
    return ost;
}
std::string load_semester(std::istream& ist){
    std::string semester;
    std::getline(ist, semester);
    return semester;
}