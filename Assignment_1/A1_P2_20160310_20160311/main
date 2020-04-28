#include <iostream>
#include "Fraction.h"
#include "FractionCalculator.h"
using namespace std;

int main()
{
    Fraction number1,number2;
    FractionCalculator LastResult;
    cout<<"The first fraction number : ";cin>>number1;
    cout<<"The second fraction number : ";cin>>number2;
    char again=' ';
    int choice;
    cout<<"now that's the allowed operation you can do,please enter your choice number: \n";
    while (true)
    {
        cout<<"\t1-addition.\n\t2-subtraction\n\t3-multiplying\n\t4-dividing";
        cout<<"\n\t5-comparing by (<)\n\t6-comparing by (>)\n\t7-comparing by (==)\n\t8-comparing by (<=)\n\t9-comparing by (>=)\n";
        cout<<"your choice : ";cin>>choice;
        if(choice==1)
        {
            LastResult.Frac=number1+number2;
            cout<<"The Addition is "<<LastResult.Frac<<endl;
        }
        else if(choice==2)
        {

        }
        else if(choice==3)
        {

        }
        else if(choice==4)
        {

        }
        else if(choice==5)
        {

        }
        else if(choice==6)
        {

        }
        else if(choice==7)
        {

        }
        else if(choice==8)
        {

        }
        else if(choice==9)
        {

        }
        else
        {
            cout<<"Invalid choice!!\n";
            continue;
        }
        choose1:
            cout<<"do you want to do another Operation (Y or N): ";cin>>again;
            if (again=='Y'||again=='y')
                continue;
            else if (again=='N'||again=='n')
                break;
            else
            {
                cout<<"Invalid Answer!!\n";
                goto choose1;
            }
    }
    return 0;
}
