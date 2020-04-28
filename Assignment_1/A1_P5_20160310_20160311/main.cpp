#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void RecPermute(string soFar, string rest,set <string> &temp)
{
    if (rest == "") // No more characters
        temp.insert(soFar); // Print the word
    else // Still more chars
    // For each remaining char
    for (int i = 0; i < rest.length(); i++) {
        string next = soFar + rest[i]; // Glue next char
        string remaining = rest.substr(0, i)+ rest.substr(i+1);
        RecPermute(next, remaining, temp);
}
}
// "wrapper" function
void ListPermutations(string s) {
    set <string> permutations;
    RecPermute("", s , permutations);
    for (set<string>::iterator place=permutations.begin();place!=permutations.end();place++)
        cout<<*place<<endl;
}

int main()
{
    string name;
    cin>>name;
    ListPermutations(name);
    return 0;
}
