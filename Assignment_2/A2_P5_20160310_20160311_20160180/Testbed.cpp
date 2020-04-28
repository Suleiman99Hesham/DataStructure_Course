#include "Testbed.h"
#include <bits/stdc++.h>
#include <ctime>
Testbed::Testbed()
{

}

vector <int> Testbed::GenerateRandomList(int Min,int Max,int Size){
    vector <int> set_number;
    for (int i=0;i<Size;i++){
        set_number.push_back(Min + (rand()%(int)(Max-Min+1)));
    }
    return set_number;
}

vector <int> Testbed::GenerateReversedOrderList(int Min,int Max,int Size){
    vector <int> set_number;
    set_number=GenerateRandomList(Min,Max,Size);
    for (int i=0;i<Size;i++){
        for (int j=i;j<Size;j++){
            if (set_number[i]<set_number[j]){
                swap(set_number[i],set_number[j]);
            }
        }
    }
    return set_number;
}
double Testbed::RunOnce(Sorter *tp , vector <int>  Array,int Size){
    clock_t needed_time=clock();
    tp->Sort(Array,Size);
    needed_time=clock()-needed_time;
    return (double)(needed_time) / CLOCKS_PER_SEC;
}
double Testbed::RunAndAverage(Sorter * tp ,int type , int Min,int Max, int Size,int sets_num){
    double avgTime,myTime=0;
    vector <int> set_number;
    for (int i=0;i<sets_num;i++){
        if (type==0){
            set_number=GenerateRandomList(Min,Max,Size);
            myTime+=RunOnce(tp,set_number,set_number.size());
        }
        else if (type==1){
            Testbed obj;
            set_number=GenerateReversedOrderList(Min,Max,Size);
            myTime+=RunOnce(tp,set_number,set_number.size());        }
    }
    avgTime=myTime/sets_num;
    return (avgTime);
}
void Testbed::RunExperient (Sorter * tp, int type,int Min,int Max, int min_val,int max_val,int sets_num,int step){
    while (min_val<=max_val){
        cout<<min_val<<"    is    "<<fixed<<RunAndAverage(tp,type,Min,Max,min_val,sets_num)<<endl;
        min_val+=step;
    }
}
