#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "Sorter.h"
#include <bits/stdc++.h>
using namespace std;

class SelectionSort:public Sorter
{
    public:
        SelectionSort();
        void Sort(vector <int> &arr,int Size);

    protected:

    private:
};

#endif // SELECTIONSORT_H
