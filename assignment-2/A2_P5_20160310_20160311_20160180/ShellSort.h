#ifndef SHELLSORT_H
#define SHELLSORT_H
#include "Sorter.h"
#include <bits/stdc++.h>
using namespace std;

class ShellSort:public Sorter
{
    public:
        ShellSort();
        void Sort(vector<int>&arr,int Size);
    protected:

    private:
};

#endif // SHELLSORT_H
