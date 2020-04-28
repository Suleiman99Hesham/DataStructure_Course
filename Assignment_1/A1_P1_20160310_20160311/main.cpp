#include <iostream>
#include "BigDecimalInt.h"
using namespace std;
int BigDecimalInt::negative_tracer=0;
int main()
{
    string num1,num2;
    int choice2=0,lock=0,check=0;
    cout<<"enter the first number: ";
    cin>>num1;
    while (check==0){
        for (int i=0;i<num1.length();i++){
            if ((num1[i]!='0') && (num1[i]!='1') && (num1[i]!='2') && (num1[i]!='3') && (num1[i]!='4') && (num1[i]!='5') && (num1[i]!='6') && (num1[i]!='7') && (num1[i]!='8') && (num1[i]!='9')&&(num1[0]!='-')){
                lock++;
                break;}
            else
                continue;
        }
        if (lock ==1){
            cout<<"please enter a valid number : ";
            cin>>num1;
            lock--;}
        else
            check=1;
    }
    check=0;
    lock=0;
    cout<<"enter the second number: ";
    cin>>num2;
    while (check==0){
        for (int i=0;i<num2.length();i++){
            if ((num2[i]!='0') && (num2[i]!='1') && (num2[i]!='2') && (num2[i]!='3') && (num2[i]!='4') && (num2[i]!='5') && (num2[i]!='6') && (num2[i]!='7') && (num2[i]!='8') && (num2[i]!='9')&&(num2[0]!='-')){
                lock++;
                break;}
            else
                continue;
        }
        if (lock ==1){
            cout<<"please enter a valid number : ";
            cin>>num2;
            lock--;
            }
        else
            check++;
    }
    BigDecimalInt firstnumber(num1);
    BigDecimalInt secondnumber(num2);
    cout<<"number 1 = "<<firstnumber<<endl<<"number 2 = "<<secondnumber<<endl;
    BigDecimalInt thirdnumber;
    BigDecimalInt forthnumber;
    BigDecimalInt fifthnumber;
    BigDecimalInt sixthnumber;
    while (choice2 !=3){
       cout<<"\n1-( + ) 2-( - )  3-exit\n";
       cout<<"Please enter your choice: ";
       cin>>choice2;
       while (choice2!=1 && choice2!=2 && choice2!=3 ){
           cout<<"PLEASE ENTER A VALID CHOICE : ";
           cin>>choice2;
        }
        if (choice2==1){
            if (thirdnumber.negative_tracer==0){
                thirdnumber=firstnumber+secondnumber;
                cout<<"number 1 + number 2 = "<<thirdnumber<<endl;
            }
            else if (thirdnumber.negative_tracer==2){
                thirdnumber=firstnumber+secondnumber;
                cout<<"number 1 + number 2 = -"<<thirdnumber<<endl;
            }
            else if (thirdnumber.negative_tracer==1){
                if (num1[0]=='-'){
                    thirdnumber=secondnumber-firstnumber;
                    cout<<thirdnumber<<endl;
                }
                else{
                    thirdnumber=firstnumber-secondnumber;
                    cout<<thirdnumber<<endl;
                }
            }

        }
        else if (choice2==2){
            if (forthnumber.negative_tracer==0){
                forthnumber=firstnumber-secondnumber;
                cout<<forthnumber;
            }
            else if (forthnumber.negative_tracer==2){
                forthnumber=secondnumber-firstnumber;
                cout<<"-"<<forthnumber;
            }
            else if (forthnumber.negative_tracer==1){
                if (num1[0]=='-' && num2[0]!='-'){
                    forthnumber=firstnumber+secondnumber;
                    cout<<"number 1 - number 2 = "<<forthnumber;
                }
                else if (num2[0]=='-' && num1[0]!='-') {
                    forthnumber=firstnumber+secondnumber;
                    cout<<"number 1 - number 2 = "<<forthnumber;
                }
            }
        }
        else
            continue;
    }
    return 0;
}
