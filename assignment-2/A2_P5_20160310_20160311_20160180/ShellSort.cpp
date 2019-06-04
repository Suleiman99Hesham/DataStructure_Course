#include "ShellSort.h"
#include <iostream>
ShellSort::ShellSort()
{
    //ctor
}
void ShellSort::Sort(vector <int> &arr,int Size){
    for (int Gap=Size-2;Gap>0;Gap/=2){
        for(int i=Gap+1;i<Size;i++)
            for(int j=i-Gap;j>=0;j-=Gap){
                if(arr[j]>arr[j+Gap]){
                    int Temp=arr[j];
                    arr[j]=arr[j+Gap];
                    arr[j+Gap]=Temp;
                }
            }
    }
}
