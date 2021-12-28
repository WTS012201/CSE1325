#include "subject.h"

std::ostream& operator<<(std::ostream& ost, const Subject subject){
    std::string s;
    switch(subject){
        case Subject::READING: s = "reading"; break;
        case Subject::WRITING: s = "writing"; break;
        case Subject::MATH: s = "math"; break;
        case Subject::SCIENCE: s = "science"; break;
        case Subject::HISTORY: s = "history"; break;
        case Subject::ART: s = "art"; break;
        case Subject::SPORTS: s = "sports"; break;
        case Subject::MUSIC: s = "music"; break;
    }
    ost << s;
    return ost;
}
std::string load_subject(std::istream& ist){
    std::string subject;
    std::getline(ist, subject);
    return subject;
}