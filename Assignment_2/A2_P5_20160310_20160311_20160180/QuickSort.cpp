#include "QuickSort.h"

QuickSort::QuickSort()
{
    //ctor
}
int QuickSort::partitionArr(vector<int>& x,int Start,int End){
    int Pivot,PartIndex;
    PartIndex=Start;
    Pivot=x[End];
    for(int i=Start;i<End;i++){
        if (x[i]<Pivot){
            int Temp=x[PartIndex];
            x[PartIndex]=x[i];
            x[i]=Temp;
            PartIndex++;
        }
    }
    int Temp=x[PartIndex];
    x[PartIndex]=Pivot;
    x[End]=Temp;
    return PartIndex;
}
void QuickSort::Quick_Sort(vector<int> &x,int Start,int End){
    if (Start<End){
        int Index=partitionArr(x,Start,End);
        Quick_Sort(x,Start,Index-1);
        Quick_Sort(x,Index+1,End);
    }
}
void QuickSort::Sort(vector <int> &arr,int Size){
    int Start=0,End=Size-1;
    Quick_Sort(arr,Start,End);
}
