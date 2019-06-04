#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
void NormalInsertion(vector <int> &arr,int Size)
{
    int temp, index;
    for(int i=0;i<Size;i++)
    {
        temp=arr[i];
        index=i-1;
        while (index>=0&&arr[index]>temp)
        {
            arr[index+1]=arr[index];
            index-=1;
        }
        arr[index+1]=temp;
    }
}
void DoubleInsertion(vector <int> &arr,int Size)
{
    int temp1,temp2,index;
    for(int i=1;i<Size;i+=2)
    {
        if(arr[i]>=arr[i+1])
        {
            temp1=arr[i];
            temp2=arr[i+1];
        }
        else
        {
            temp1=arr[i+1];
            temp2=arr[i];
        }
        index=i-1;
        while(index>=0&&arr[index]>temp1)
        {
            arr[index+2]=arr[index];
            index-=1;
        }
        arr[index+2]=temp1;
        while(index>=0&&arr[index]>temp2)
        {
            arr[index+1]=arr[index];
            index-=1;
        }
        arr[index+1]=temp2;
    }
}
int main()
{
    int Size=10000,tries=20;
    for (int j=0;j<=tries;j++){
        cout<<"the size is : "<<Size<<endl;
        vector <int> set_number;
        vector <int> another_set;
        for (int i=0;i<Size;i++){
            set_number.push_back(1 + (rand()%(int)(1100000-1+1)));
        }
        another_set=set_number;
        clock_t start=clock();
        DoubleInsertion(set_number,Size);
        clockid_t End=clock();
        clockid_t Ti;
        Ti=End-start;
        cout<<"double insertion time : "<<(long double)Ti/CLOCKS_PER_SEC<<endl;
        start=clock();
        NormalInsertion(another_set,Size);
        End=clock();
        Ti=End-start;
        cout<<"normal insertion time : "<<(long double)Ti/CLOCKS_PER_SEC<<endl;
        cout<<"----------------------------------------------------------------\n";
        Size+=100;
    }
    return 0;
}
