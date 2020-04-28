#include <iostream>

using namespace std;
double power (double base,double pwr)
{
    double result=0;
    if (pwr==0)
        return 1;
    else
        result+=base;
        return result*power(base,pwr-1);
}
double power_half(int base,int pwr)
{

    if (pwr==1)
        return base;
    else if (pwr==0)
        return 1;
    else
        if(pwr%2==0)
        {
            return power_half(base,pwr/2)*power_half(base,pwr/2);
        }
        else
        {
            pwr--;
            return base*power_half(base,pwr/2)*power_half(base,pwr/2);
        }
}
int main()
{
    cout<<power(2,0)<<endl;
    cout<<power_half(2,0)<<endl;
    cout<<"-------------------------\n";
    cout<<power(2,1)<<endl;
    cout<<power_half(2,1)<<endl;
    cout<<"-------------------------\n";
    cout<<power(2,2)<<endl;
    cout<<power_half(2,2)<<endl;
    cout<<"-------------------------\n";
    cout<<power(2,3)<<endl;
    cout<<power_half(2,3)<<endl;
    cout<<"-------------------------\n";
    cout<<power(2,4)<<endl;
    cout<<power_half(2,4)<<endl;
    cout<<"-------------------------\n";
    cout<<power(2,5)<<endl;
    cout<<power_half(2,5)<<endl;
    cout<<"-------------------------\n";
    cout<<power(2,6)<<endl;
    cout<<power_half(2,6)<<endl;
    cout<<"-------------------------\n";
    cout<<power(2,7)<<endl;
    cout<<power_half(2,7)<<endl;
    cout<<"-------------------------\n";
    return 0;
}
