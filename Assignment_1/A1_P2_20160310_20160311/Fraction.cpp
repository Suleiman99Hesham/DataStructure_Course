#include "Fraction.h"
#include <bits/stdc++.h>
Fraction::Fraction()
{
    high=0;
    low=0;
}
Fraction::Fraction(int x,int y)
{
    high=x;
    low=y;
}
Fraction Fraction::operator+(Fraction x)
{
    Fraction temp;
    temp.low=low*x.low;
    temp.high=(high*x.low)+(low*x.high);
    return temp;
}
Fraction Fraction::operator-(Fraction x)
{
    Fraction temp;
    temp.low=low*x.low;
    temp.high=(high*x.low)-(low*x.high);
    return temp;
}
Fraction Fraction::operator*(Fraction x)
{
    Fraction temp;
    temp.high=high*x.high;
    temp.low=low*x.low;
    return temp;
}
Fraction Fraction::operator/(Fraction x)
{
    Fraction temp;
    int fac;
    fac=x.high;
    x.high=x.low;
    x.low=fac;
    temp.high=high*x.high;
    temp.low=low*x.low;
    return temp;
}
bool Fraction::operator>(Fraction x)
{
    int temp1=high*x.low;
    int temp2=x.high*low;
    if(temp1>temp2)
        return true;
    else
        return false;
}
bool Fraction::operator<(Fraction x)
{
    int temp1=high*x.low;
    int temp2=x.high*low;
    if(temp1<temp2)
        return true;
    else
        return false;
}
bool Fraction::operator==(Fraction x)
{
    int temp1=high*x.low;
    int temp2=x.high*low;
    if(temp1==temp2)
        return true;
    else
        return false;
}
bool Fraction::operator>=(Fraction x)
{
    int temp1=high*x.low;
    int temp2=x.high*low;
    if(temp1>=temp2)
        return true;
    else
        return false;
}
bool Fraction::operator<=(Fraction x)
{
    int temp1=high*x.low;
    int temp2=x.high*low;
    if(temp1<=temp2)
        return true;
    else
        return false;
}
int Fraction::gcd(int x, int y)
{
    int result=1;
    if(x>y)
    {
        for(int i=1;i<=y;i++)
            {
                if(x%i==0&&y%i==0)
                    result=i;
            }
        return result;
    }
    if(y>x)
    {
        for(int i=1;i<=x;i++)
            {
                if(x%i==0&&y%i==0)
                    result=i;
            }
        return result;
    }
    else
        return x;
}
void Fraction::reduce()
{
    int temp1=high,temp2=low;
    high/=gcd(temp1,temp2);
    low/=gcd(temp1,temp2);
}
int Fraction::convert(string word)
{
    int factor=word.length()-1,result=0;
    for(int i=0;i<word.length();i++)
    {
        result+=int(word[i]-48)*pow(10,factor);
        factor--;
    }
    return result;
}
istream &operator>>(istream &input,Fraction &F)
{
    string frac,hgh="",lwl="";
    bool check=false;
    cout<<"please inter the fraction in (#/#)form:";
    cin>>frac;
    for(int i=0;i<frac.length();i++)
    {
        if(frac[i]=='/')
        {
            check=true;
            continue;
        }
        if(check==false)
        {

            hgh+=frac[i];
        }
        else
            lwl+=frac[i];
    }
    F.high=F.convert(hgh);
    F.low=F.convert(lwl);
    return input;
}
ostream &operator<<(ostream &output,Fraction &F)
{
    output<<F.high<<'/'<<F.low;
    return output;
}
