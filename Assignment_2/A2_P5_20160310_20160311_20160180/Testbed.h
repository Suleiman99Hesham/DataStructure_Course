#ifndef TESTBED_H
#define TESTBED_H
#include <bits/stdc++.h>
#include "Sorter.h"
class Testbed : public Sorter
{
    public:
        Testbed ();
        vector <int> GenerateRandomList(int Min,int Max,int Size);
        vector <int> GenerateReversedOrderList(int Min,int Max,int Size);
        double RunOnce(Sorter * , vector <int>  , int );
        double RunAndAverage(Sorter * , int type , int Min , int Max, int Size,  int sets_num);
        void RunExperient (Sorter * , int type,int Min,int Max, int min_val,int max_val,int sets_num,int step);

    private:

};

#endif // TESTBED_H
