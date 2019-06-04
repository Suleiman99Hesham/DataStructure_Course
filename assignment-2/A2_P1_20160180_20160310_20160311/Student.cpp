#include <iostream>
#include "Student.h"
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

Student::Student()
{
    name=" ";
    age=0;
    grade=0.0;
}

Student::Student(string n, int a, float g)
{
    name=n;
    age=a;
    grade=g;

}

void Student::AddStudent()
{
    bool exist=true;
    cout<<"enter new student data: \n\t";
    cout<<"name: ";
    while (true)
    {
        cin>>name;
        for(int i=0;i<StudentArray.size();i++)
        {
            if(name==StudentArray[i].name)
            {
                exist=false;
                cout<<"the entered name is exist!\n\tplease enter a new one :";
                break;
            }
            if(i==StudentArray.size()-1)
                exist=true;
        }
        if (exist=true)
        {
            break;
        }
    }
    cout<<"\tage: ";
    cin>>age;
    cout<<"\tgrade: ";
    cin>>grade;
    StudentArray.push_back(*this);
}

void Student::printStudent(int PTindex)
{
    cout<<"\n\tstudent name: "<<StudentArray[PTindex].name;
    cout<<"\n\tstudent age: "<<StudentArray[PTindex].age;
    cout<<"\n\tstudent grade: "<<StudentArray[PTindex].grade<<endl;
}

int Student::SearchStudent(string n)
{
    for(int i=0; i<StudentArray.size();i++)
    {
        if (n==StudentArray[i].name)
            return i;
    }
    cout<<"this student isn't found ";
    return -1;
}
void Student::ListStudents()
{
    for(int i=0; i<StudentArray.size();i++){
        for(int j=i;j<StudentArray.size();j++){
            if(StudentArray[i].name > StudentArray[j].name)
                swap(StudentArray[i],StudentArray[j]);
        }
    }
    for(int i=0;i<StudentArray.size();i++)
    {
        printStudent(i);
    }
}

void Student::UpdateStudentGrade()
{
    cout<<"enter student name: ";
    string SrchName;
    cin>>SrchName;
    int Indxfound=SearchStudent(SrchName);
    if(Indxfound!=-1)
    {
        cout<<"\tplease enter the new grade for student: ";
        cin>>StudentArray[Indxfound].grade;
    }
    else
    {
        cout<<"there is no student with the name you entered!";
    }

}
void Student::FindHighestGrade()
{
    float HighGrade=0;
    int index=-1;
    for(int i=0; i<StudentArray.size();i++)
    {
        if(HighGrade<=StudentArray[i].grade)
            index=i;
    }

    if (index!=-1){
        cout<<"the data of highest grade student :";
        printStudent(index);
    }
    else if (index==-1){
        cout<<"You haven't enter any students yet";
    }
}
void Student::userInterface()
{
    Student object;
    while(1){
        string sChoice;
        cout<<endl;
        cout<<"\t\t\t\t\t Students data \n\n";
        cout<<"1) Add student \n";
        cout<<"2) Search student by name \n";
        cout<<"3) Update student grade \n";
        cout<<"4) show students sorted \n";
        cout<<"5) Find the highest grade student \n";
        cout<<"6) Exit \n";
        cout<<"Please Enter Your Choice: ";
        cin>>sChoice;
        while(1){
            if((sChoice!="1")&&(sChoice!="2")&&(sChoice!="3")&&(sChoice!="4")&&(sChoice!="5")&&(sChoice!="6")){
                cout<<"Please Enter a Valid Choice: ";
                cin>>sChoice;
            }
            else
                break;
        }
        if(sChoice=="1")
        {
            object.AddStudent();
        }
        if(sChoice=="2")
        {
            string SearchingName;
            cout<<"enter student name: ";
            cin>>SearchingName;
            if(SearchStudent(SearchingName)!=-1)
            {
                printStudent(SearchStudent(SearchingName));
            }
        }
        if(sChoice=="3")
            UpdateStudentGrade();
        if(sChoice=="4")
            ListStudents();
        if(sChoice=="5")
            FindHighestGrade();
        if(sChoice=="6")
            break;

    }

}


