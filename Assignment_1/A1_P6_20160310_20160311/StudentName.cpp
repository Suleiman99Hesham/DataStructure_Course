#include "StudentName.h"
#include <bits/stdc++.h>
#include <string>
using namespace std;

StudentName::StudentName()
{
    name=" ";
}

StudentName::StudentName(string N){
    int counter=0;

    for (int i=0;i<N.length()-1;i++){
        if (N[i]==' '){
            counter++;
        }
        else
            continue;
    }

    name=N;
    if (counter==1) {
        name+=' ';
        for (int i=0;i<N.length()-1;i++){
            if (N[i]==' '){
                for (int j=i+1;j<N.length();j++){
                    name+=N[j];
                }
            }
        }
    }

    if (counter==0){
        name=name+' '+name+' '+name;
    }
        cout<<name<<endl;
}
void StudentName::print(){
    int counter=1;
    cout<<counter<<") ";
    counter++;
    for (int i=0;i<name.length();i++){
        if (name[i]!=' '){
            cout<<name[i];
        }
        else if (name[i]==' '){
            cout<<endl<<counter<<") ";
            counter++;

        }
    }
}

void StudentName::Replace(int i,int j){
    int counter=0;
    for (int k=0;k<name.length();k++){
        if (name[k]==' ')
            counter++;
    }
    if ((i-1>counter) || (j-1>counter))
        cout<<"False you can't swap those names because they are out of range";

    else {
        string *tempname;
        string temp="";
        int place=0;
        tempname = new string [counter+1];
        for (int k=0;k<name.length();k++){
            if (name[k]!=' '){
                temp+=name[k];
                if (k!=name.length()-1)
                    continue;
            }

            tempname[place]=temp;
            temp="";
            place++;
        }
        string temporarly_name;
        temporarly_name=tempname[j-1];
        tempname[j-1]=tempname[i-1];
        tempname[i-1]=temporarly_name;
        for (int k=0;k<counter+1;k++){
            cout<<tempname[k]<<" ";
        }
    }
}

