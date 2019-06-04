#ifndef MATRIX_H
#define MATRIX_H
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Matrix
{
    public:
        Matrix();
        Matrix(int,int);
        Matrix(int,int,char);
        ~Matrix();
        Matrix operator+(const Matrix<T> &);
        Matrix operator-(const Matrix<T> &);
        Matrix operator*(const Matrix<T> &);
        Matrix transpose();
        template<class T2>
        friend ostream & operator<<(ostream&out,Matrix<T2> &obj);
        template<class T2>
        friend istream & operator>>(istream&in,Matrix<T2>  &obj);
        friend class MatrixCalculator;
    private:
        T **new_Matrix;
        int first_Dimension,second_Dimension;
};

template <class T>
Matrix<T>::Matrix()
{}

template <class T>
Matrix<T>::~Matrix(){
    for(int i=0;i<second_Dimension;i++){
        delete[] new_Matrix;
    }
}

template <class T>
Matrix<T>::Matrix(int a, int b){
    if ((a==0)||(b==0)){
      cout<<"Dimension can't Be Zero\n";
    }
    else{
        first_Dimension=a;
        second_Dimension=b;
        new_Matrix = new T*[first_Dimension];
        for (int i=0;i<first_Dimension;i++) {
            new_Matrix[i] = new T[second_Dimension];
        }
        cout<<"Enter Matrix Elements: \n";
        for(int i = 0; i < first_Dimension; i++)
            for(int j = 0; j < second_Dimension; j++)
                cin>>new_Matrix[i][j];
    }
}

template <class T>
Matrix<T>::Matrix(int a, int b, char c){
    first_Dimension=a;
    second_Dimension=b;
    new_Matrix=new T*[first_Dimension];
    for (int i=0;i<first_Dimension;i++) {
        new_Matrix[i]=new T[second_Dimension];
    }
}

template <class T2>
istream & operator>>(istream&in , Matrix<T2> &obj){
    string new_dimension="",new_first_dimension="",new_second_dimension="";
    int first_Dimension,second_Dimension,lock=1;
    while (true)
    {
        new_dimension="",new_first_dimension="",new_second_dimension="";
        cout<<"Please Enter Matrix Dimensions as ( AxB ): ";
        in>>new_dimension;
        int i=0;
        for (i=0;i<new_dimension.length()+1;i++)
        {
            if((new_dimension[i]=='x')||(new_dimension[i]=='X'))
            {
                lock=0;
                break;
            }
            else{
                new_first_dimension+=new_dimension[i];
            }
        }
        stringstream changeNum(new_first_dimension);
        changeNum>>first_Dimension;

        for (i+=1;i<new_dimension.length()+1;i++)
        {
            new_second_dimension+=new_dimension[i];
        }
        stringstream changeDen(new_second_dimension);
        changeDen>>second_Dimension;
        if (lock==1)
            cout<<"\nPlease enter Invalid Formula \n";
        else if((second_Dimension==0)||(first_Dimension==0))
        {
           cout<<"Dimension can't Be Zero\n";
        }
        else
            break;
    }
    obj.first_Dimension=first_Dimension;
    obj.second_Dimension=second_Dimension;
    return in;
}

template<class T2>
ostream & operator<<(ostream &out , Matrix<T2> &obj){
    for (int i=0;i<obj.first_Dimension;i++)
    {
        cout<<"|";
        for (int j=0;j<obj.second_Dimension;j++)
        {
            cout<<setw(3)<<obj.new_Matrix[i][j];
            if (j<obj.second_Dimension-1)
                cout<<"  -";
        }
        cout<<setw(3)<<"|"<<endl;
    }
    out<<"\n";
    return out;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &obj){
    char c='+';
    Matrix<T> t(obj.first_Dimension,obj.second_Dimension,c);
    for(int i = 0; i < obj.first_Dimension; i++)
        for(int j = 0; j < obj.second_Dimension; j++)
            t.new_Matrix[i][j] = new_Matrix[i][j] + obj.new_Matrix[i][j];
    return t;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &obj)
{
    char c='-';
    Matrix<T> t(obj.first_Dimension,obj.second_Dimension,c);
    for(int i = 0; i < obj.first_Dimension; i++)
        for(int j = 0; j < obj.second_Dimension; j++)
            t.new_Matrix[i][j] = new_Matrix[i][j] - obj.new_Matrix[i][j];
    return t;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &obj)
{
    char c='*';
    Matrix<T> t(first_Dimension,obj.second_Dimension,c);
    for(int i = 0; i < first_Dimension; i++)
        for(int j = 0; j < obj.second_Dimension; j++)
            t.new_Matrix[i][j]=0;

    for(int i = 0; i < first_Dimension; i++)
        for(int j = 0; j < obj.second_Dimension; j++)
            for(int k = 0; k < obj.first_Dimension; k++)
            t.new_Matrix[i][j]+= new_Matrix[i][k] * obj.new_Matrix[k][j];

    return t;
}

template <class T>
Matrix<T> Matrix<T>::transpose()
{
    char c='@';
    Matrix<T> t(second_Dimension,first_Dimension,c);
    for(int i = 0; i < second_Dimension; i++)
        for(int j = 0; j < first_Dimension; j++)
            t.new_Matrix[i][j]=new_Matrix[j][i];
    return t;
}


#endif // MATRIX_H
