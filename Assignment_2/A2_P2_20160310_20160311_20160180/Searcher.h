#ifndef SEARCHER_H
#define SEARCHER_H
#include <bits/stdc++.h>
using namespace std;

class Searcher
{
    public:
        Searcher();
        void loadFile(int);
        int binarySearch(string );
        void testPerformance(int );
    private:
        vector <string> words;
        int i=0;
};

#endif // SEARCHER_H
