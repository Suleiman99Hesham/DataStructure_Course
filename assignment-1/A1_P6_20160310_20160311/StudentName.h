#ifndef STUDENTNAME_H
#define STUDENTNAME_H
#include <string>
using namespace std;

class StudentName
{
    public:
        StudentName();
        StudentName(string N);
        void print();
        void Replace(int i,int j);

    private:
        string name;
};

#endif // STUDENTNAME_H
