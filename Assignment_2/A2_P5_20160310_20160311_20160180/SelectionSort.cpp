#include "SelectionSort.h"

SelectionSort::SelectionSort()
{
    //ctor
}
void SelectionSort::Sort(vector <int> &arr,int Size){
    for(int i=0;i<Size-1;i++){
            int MinInex=i;
            for(int j=i+1;j<Size;j++){
                if(arr[MinInex]>arr[j])
                    MinInex=j;
            }
            if(MinInex!=i){
                int Temp=arr[i];
                arr[i]=arr[MinInex];
                arr[MinInex]=Temp;
            }
       }
}
