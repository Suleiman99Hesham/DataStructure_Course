#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Sorter.h"
#include <bits/stdc++.h>
using namespace std;

class QuickSort: public Sorter
{
    public:
        QuickSort();
        int partitionArr(vector<int>&x,int Start,int End);
        void Quick_Sort(vector <int>&x,int start,int End);
        void Sort(vector<int> &arr,int Size);
    protected:

    private:
};

#endif // QUICKSORT_H
