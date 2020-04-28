#include <iostream>
#include <bits/stdc++.h>
#include "Searcher.h"

using namespace std;
int main()
{
    for(int i=10000;i<=80000;i+=10000)
    {
        Searcher object;
        object.loadFile(i);
        cout<<"NO of words "<<i<<" :\n--------------------\n";
        cout<<"founded word: "<<endl;
        object.testPerformance(1);
        cout<<"unfounded word: "<<endl;
        object.testPerformance(2);
        cout<<"********************************************************"<<endl;


    }
    return 0;
}
