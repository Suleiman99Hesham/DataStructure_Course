#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
using namespace std;
class Student
{
    public:
        Student();
        Student(string n, int a, float g);
        void AddStudent();
        int SearchStudent(string n);
        void ListStudents();
        void UpdateStudentGrade(); ///(user enters student name and the new grade)
        void FindHighestGrade();
        void printStudent(int);
        void userInterface();
    private:
        int age;
        string name;
        float grade;
        static vector<Student> StudentArray ;
};

#endif // STUDENT_H
