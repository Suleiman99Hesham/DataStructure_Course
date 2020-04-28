#include "Searcher.h"
#include <bits/stdc++.h>
using namespace std;
Searcher::Searcher()
{
    //ctor
}
void Searcher::loadFile(int bounds){
    fstream file("wordsEn.txt",ios::in);
    while(!file.eof()){
        string temp;
        file>>temp;
        if(words.size()<=bounds)
        {
            words.push_back(temp);
        }
        else
        {
            break;
        }
    }
    file.close();
}
int Searcher::binarySearch(string found){
    int low=0,high=words.size()-1,mid=(low+high)/2;
    while (low<high){
        i++;
        if (found==words[mid]){
            i++;
            return mid;
        }
        else if(found>words[mid]){
            i+=2;
            low=mid+1;
        }
        else
        {
            i+=3;
            high=mid-1;
        }
        mid=(low+high)/2;
    }
    return -1;
}
void Searcher::testPerformance(int Case){
    int Size=100;
    clockid_t search_time,start_time,End_time;
    double ave_time=0;
    for (int i=0;i<Size;i++){
        if(Case==1){
            start_time=clock();
            binarySearch(words[1+(rand()%(words.size()-1+1))]);
            End_time=clock();
            search_time=End_time-start_time;
        }
        else
        {
            start_time=clock();
            binarySearch("suleimanandkareem");
            End_time=clock();
            search_time=End_time-start_time;
        }
        ave_time+=(double)search_time;
    }
    ave_time/=Size;
    cout<<"average time : "<<fixed<<ave_time<<endl;
    cout<<"average number of comparisons : "<<i/100<<endl;
}

