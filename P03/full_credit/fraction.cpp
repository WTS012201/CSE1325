#include "fraction.h"
#include <iostream>
#include <cmath>
#include <string>
void GCD(int &a, int &b){
    int c = std::abs(a)/2;
    while(a % c != 0 || b % c != 0){--c;}
    a/=c;
    b/=c;
}
Fraction::Fraction(int numerator, int denominator) : _n{numerator}, _d{denominator} {
    if(_n != 0)
        reduce();
}
void Fraction::reduce(){
    if(_d < 0){
        _n = _n*(-1);
        _d = _d*(-1);
    }
    if(std::abs(_n) == _d){
        _n /= _d;
        _d = 1;
        return;
    }
    std::abs(_n) > _d ? GCD(_n, _d) : GCD(_d, _n);
}
Fraction Fraction::operator-(){
    return Fraction{_n*(-1), _d};
}
Fraction Fraction::operator+(Fraction &rhs){
    return Fraction{_n*rhs._d + rhs._n*_d, _d*rhs._d};
}
Fraction Fraction::operator-(Fraction &rhs){
    return Fraction{_n*rhs._d - rhs._n*_d, _d*rhs._d};
}
Fraction Fraction::operator*(Fraction &rhs){
    return Fraction{_n*rhs._n, _d*rhs._d};
}
Fraction Fraction::operator/(Fraction &rhs){
    return Fraction{_n*rhs._d, _d*rhs._n};
}
std::ostream& operator<<(std::ostream &ost, Fraction &m){
    ost << m._n << '/' << m._d;
    return ost;
}
std::istream& operator>>(std::istream &ist, Fraction &m){
    std::string s;
    ist >> s;
    int pos = s.find('/');
    if(pos<0)
        throw std::runtime_error{"Read a bad fraction"};
    m._n = std::stoi(s.substr(0,pos));
    m._d = std::stoi(s.substr(pos + 1));
    m.reduce();
    if(!ist)
        throw std::runtime_error{"Read a bad fraction"};
    return ist;
}
bool operator!=(const Fraction &lhs, const Fraction &rhs){
    bool a, b;
    lhs._n != rhs._n ? a = true : a = false;
    lhs._d != rhs._d ? b = true : b = false;
    return a && b;
}
