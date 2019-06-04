#ifndef FRACTION_H
#define FRACTION_H
#include <bits/stdc++.h>
using namespace std;
class Fraction
{
    public:
        Fraction();
        Fraction(int,int);
        Fraction operator+(Fraction);
        Fraction operator-(Fraction);
        Fraction operator*(Fraction);
        Fraction operator/(Fraction);
        bool operator>(Fraction);
        bool operator<(Fraction);
        bool operator==(Fraction);
        bool operator>=(Fraction);
        bool operator<=(Fraction);
        int gcd(int,int);
        void reduce();
        int convert(string);
        friend istream &operator>>(istream &input,Fraction &F);
        friend ostream &operator<<(ostream &output,Fraction &F);
    private:
        int high,low;
};

#endif // FRACTION_H
