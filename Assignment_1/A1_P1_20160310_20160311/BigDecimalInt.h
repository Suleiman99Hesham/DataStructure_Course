#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <bits/stdc++.h>
using namespace std;
class BigDecimalInt
{
    public:
        BigDecimalInt();
        BigDecimalInt (string decStr);
        BigDecimalInt (int decInt);
        BigDecimalInt operator+ (BigDecimalInt& anotherDec);
        BigDecimalInt operator- (BigDecimalInt& anotherDec);
        int Size();
        static int negative_tracer;
        friend ostream & operator <<(ostream & out, const BigDecimalInt& b );
        int place=0,checker=0;
    private:

        string number;
        int *decNum ;
        int counter=0,num1=0,sent=0,times=0,temp=0,difference=0,carry=0;
};

#endif // BIGDECIMALINT_H
