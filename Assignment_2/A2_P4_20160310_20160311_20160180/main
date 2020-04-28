#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int BinarySearch (vector<int>& arr,int element)
{
    int low=0,high=element-1,mid=(low+high)/2;
    while(low<high)
    {
        if(low==high)
        {
            return low;
        }
        if(arr[element] > arr[mid])
        {
            low=mid+1;
        }
        if(arr[element]<=arr[mid])
        {
            high=mid-1;
        }
        mid=(low+high)/2;
    }
    return mid;
}
void InsertionSort(vector<int>& arr,int ASize)
{
    int temp,j;
    for(int i=1;i<ASize;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0&&temp<arr[j])
        {
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=temp;
    }
}
void InsertionSortBinary(vector<int>& arr,int ASize)
{
    int index,temp,j;
    for(int i=1;i<ASize;i++)
    {
        temp=arr[i];
        index=BinarySearch(arr,i);
        if(arr[index]<temp)
        {
            index++;
        }
        j=i-1;
        while(j>=index)
        {
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=temp;
    }
}
vector<int> ArrayList;
int main()
{
    for(int i=1000;i<=20000;i+=1000)
    {
        for(int j=0;j<i;j++)
        {
            ArrayList.push_back(1+(rand()&(int)(1100000-1+1)));
        }
        clock_t sstart=clock();
        InsertionSortBinary(ArrayList,i);
        float stop=((float)sstart/CLOCKS_PER_SEC);
        cout<<"binary algorithm is: "<<stop;
        sstart=clock();
        InsertionSort(ArrayList,i);
        stop=((float)sstart/CLOCKS_PER_SEC);
        cout<<endl<<"normal algorithm is: "<<stop<<endl;
        cout<<"**********************************************************"<<endl;
        ArrayList.clear();
    }
    return 0;
}
