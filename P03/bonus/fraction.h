#ifndef __FRACTION_H
#define __FRACTION_H
#include <iostream>
class Fraction{
    int _n;
    int _d;
    private:
        void reduce();
        int compare(Fraction& rhs);
    public:
        Fraction(int numerator = 0, int denominator = 1);
        Fraction operator-();
        Fraction operator+(Fraction& rhs);
        Fraction operator-(Fraction& rhs);
        Fraction operator*(Fraction& rhs);
        Fraction operator/(Fraction& rhs);
        inline bool operator==(Fraction& rhs){return (compare(rhs) == 0);}
        inline bool operator!=(Fraction& rhs){return (compare(rhs) != 0);}
        inline bool operator<(Fraction& rhs){return (compare(rhs) < 0);}
        inline bool operator<=(Fraction& rhs){return (compare(rhs) <= 0);}
        inline bool operator>(Fraction& rhs){return (compare(rhs) > 0);}
        inline bool operator>=(Fraction& rhs){return (compare(rhs) >= 0);}
        friend std::ostream& operator<<(std::ostream& ost, Fraction& m);
        friend std::istream& operator>>(std::istream& ost, Fraction& m);
        friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
};
#endif