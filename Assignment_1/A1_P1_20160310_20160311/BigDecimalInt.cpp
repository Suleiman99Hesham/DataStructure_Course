#include "BigDecimalInt.h"
#include <bits/stdc++.h>
using namespace std;

BigDecimalInt::BigDecimalInt()
{
    //ctor
}
BigDecimalInt :: BigDecimalInt(string decStr)
{
    number=decStr;
    if (decStr[0]=='-'){
        string temp;
        for (int i=1;i<decStr.length();i++){
            temp+=decStr[i];
        }
        decStr=temp;
        negative_tracer++;
    }
    decNum = new int [decStr.length()];
    counter=decStr.length();
    for (int i=0; i<decStr.length(); i++)
    {
        if(decStr[i]=='0')
            num1=0;
        else if(decStr[i]=='1')
            num1=1;
        else if(decStr[i]=='2')
            num1=2;
        else if(decStr[i]=='3')
            num1=3;
        else if(decStr[i]=='4')
            num1=4;
        else if(decStr[i]=='5')
            num1=5;
        else if(decStr[i]=='6')
            num1=6;
        else if(decStr[i]=='7')
            num1=7;
        else if(decStr[i]=='8')
            num1=8;
        else
            num1=9;

        decNum[i]=num1;
    }
}

BigDecimalInt :: BigDecimalInt(int decInt)
{
    temp=decInt;
    while (temp>0)
    {
        temp/=10;
        times++;
    }
    decNum= new int [times];
    while (decInt>0)
    {
        sent=decInt%10;
        decInt/=10;
        decNum[counter]=sent;
        cout<<decNum[counter]<<endl;
        counter++;
    }
}

    ostream& operator<<(ostream & out,const BigDecimalInt& b)
    {
        for (int i=0; i<b.counter; i++)
        {
            out<<b.decNum[i];
        }
        return out;
    }

BigDecimalInt BigDecimalInt :: operator+ (BigDecimalInt& anotherDec)
{
    BigDecimalInt thirednumber;
    if (number.length()>=anotherDec.number.length())
    {
        thirednumber.decNum=new int [number.length()];
        thirednumber.counter=counter;
        difference=number.length()-anotherDec.number.length();
        for (int i=number.length(); i>difference; i--)
        {
            thirednumber.decNum[i-1]=decNum[i-1]+anotherDec.decNum[i-1-difference];
        }
        for (int i=difference; i>0; i--)
        {
            thirednumber.decNum[i-1]=decNum[i-1];
        }
        for (int i=number.length(); i>0; i--)
        {
            if (thirednumber.decNum[i-1]>9 && i!=1)
            {
                thirednumber.decNum[i-1]-=10;
                thirednumber.decNum[i-2]+=1;
            }
        }
    }
    else
    {
        thirednumber.decNum = new int [anotherDec.number.length()];
        difference=anotherDec.number.length()-number.length();
        thirednumber.counter=anotherDec.counter;
        for (int i=anotherDec.number.length(); i>difference; i--)
        {
            thirednumber.decNum[i-1]=decNum[i-difference-1]+anotherDec.decNum[i-1];
        }
        for (int i=difference; i>0; i--)
        {
            thirednumber.decNum[i-1]=anotherDec.decNum[i-1]+carry;
        }
        for (int i=anotherDec.counter; i>0; i--)
        {
            if (thirednumber.decNum[i-1]>9 && i!=1)
            {
                thirednumber.decNum[i-1]-=10;
                thirednumber.decNum[i-2]+=1;
            }
        }
    }
    return thirednumber;
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt& anotherDec){
    BigDecimalInt fifthnumber;
    if (counter==anotherDec.counter){
        difference=counter-anotherDec.counter;
        for (int i=0; i<counter; i++)
        {
            if (decNum[i]>anotherDec.decNum[i])
            {
                fifthnumber.place=0;
                break;
            }
            else if (decNum[i]<anotherDec.decNum[i])
            {
                fifthnumber.place=1;
                break;
            }
            else
                continue;
        }
    }
    else if (counter>anotherDec.counter)
    {
        fifthnumber.place=0;
    }
    else
        fifthnumber.place=1;
    if (fifthnumber.place==0)
    {
        if (anotherDec.checker==0)
        {
            cout<<"number 1 - number 2 = ";
        }
        fifthnumber.counter=counter;
        difference=counter-anotherDec.counter;
        fifthnumber.decNum=new int [counter];
        for (int i=0; i<counter; i++)
        {
            fifthnumber.decNum[i]=0;
        }
        for (int i=counter; i>difference; i--)
        {
            fifthnumber.decNum[i-1]=decNum[i-1]-anotherDec.decNum[i-1-difference];
        }
        for (int i=difference; i>0; i--)
        {
            fifthnumber.decNum[i-1]+=decNum[i-1];
        }
        for (int i=counter; i>0; i--)
        {
            if (fifthnumber.decNum[i-1]<0)
            {
                fifthnumber.decNum[i-1]+=10;
                fifthnumber.decNum[i-2]-=1;
            }
            else
                continue;
        }
    }
    else
    {
        if (anotherDec.checker==0)
        {
            cout<<"number 1 - number 2 = -";
        }
        fifthnumber.counter=anotherDec.counter;
        difference=anotherDec.counter-counter;
        fifthnumber.decNum=new int [anotherDec.counter];
        for (int i=0; i<anotherDec.counter; i++)
        {
            fifthnumber.decNum[i]=0;
        }
        for (int i=anotherDec.counter; i>difference; i--)
        {
            fifthnumber.decNum[i-1]=anotherDec.decNum[i-1]-decNum[i-1-difference];
        }
        for (int i=difference; i>0; i--)
        {
            fifthnumber.decNum[i-1]+=anotherDec.decNum[i-1];
        }
        for (int i=anotherDec.counter; i>0; i--)
        {
            if (fifthnumber.decNum[i-1]<0)
            {
                fifthnumber.decNum[i-1]+=10;
                fifthnumber.decNum[i-2]-=1;
            }
        }
    }
    return fifthnumber;
}

BigDecimalInt::Size(){}

