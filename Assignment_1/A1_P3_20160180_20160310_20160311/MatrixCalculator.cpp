#include "MatrixCalculator.h"
#include <iostream>
#include "Matrix.h"

MatrixCalculator:: MatrixCalculator()
{
    //Cons
}
void MatrixCalculator :: InterFace()
{
    string Choice1,Choice2;
    while(true){
        cout<<"\t\t\t Welcome to V's Matrix Calculator \n\n";
        cout<<"Press: \n";
        cout<<"1- Perform Matrix Addition \n";
        cout<<"2- Perform Matrix Subtraction \n";
        cout<<"3- Perform Matrix Multiplication \n";
        cout<<"4- Matrix Transpose \n";
        Matrix <int> mat1,mat2,mat3;
        cin>>Choice1;
        while (Choice1!="1" && Choice1 !="2" && Choice1!="3" && Choice1 !="4"){
            cout<<"Please Enter a Valid Choice: ";
            cin>>Choice1;
        }
        if (Choice1=="1")
        {
            cin>>mat1;
            cin>>mat2;

            while(true)
            {
                if ((mat1.first_Dimension==mat2.first_Dimension)&&(mat1.second_Dimension==mat2.second_Dimension))
                    break;
                else
                {
                    cout<<"\"Error\" Your Dimensions Are Not Equal\n\n";
                    cout<<"\" New Inputs \"\n";
                    cin>>mat1;
                    cin>>mat2;
                }
            }

            mat1.new_Matrix=new int*[mat1.first_Dimension];
            for (int i = 0; i < mat1.first_Dimension; i++) {
                mat1.new_Matrix[i] = new int[mat1.second_Dimension];
            }

            cout<<"Please Enter First Matrix Elements: \n";
            for(int i = 0; i < mat1.first_Dimension; i++)
                for(int j = 0; j < mat1.second_Dimension; j++)
                    cin>>mat1.new_Matrix[i][j];
            cout<<endl;
            cout<<"Please Enter Second Matrix Elements: \n";
            mat2.new_Matrix=new int*[mat1.first_Dimension];
            for (int i = 0; i < mat1.first_Dimension; i++) {
                mat2.new_Matrix[i] = new int[mat1.second_Dimension];
            }
            for(int i = 0; i < mat1.first_Dimension; i++)
                for(int j = 0; j < mat1.second_Dimension; j++)
                    cin>>mat2.new_Matrix[i][j];
            mat3=mat1+mat2;
            cout<<"The Result = \n";
            cout<<mat3;
        }
        if (Choice1=="2")
        {
            cin>>mat1;
            cin>>mat2;
            while(true)
            {
                if ((mat1.first_Dimension==mat2.first_Dimension)&&(mat1.second_Dimension==mat2.second_Dimension))
                    break;
                else
                {
                    cout<<"\"Error\" Your Dimensions Are Not Equal\n\n";
                    cout<<"\" New Inputs \"\n";
                    cin>>mat1;
                    cin>>mat2;
                }
            }

            cout<<"Please Enter First Matrix Elements: \n";
            mat1.new_Matrix=new int*[mat1.first_Dimension];
            for (int i = 0; i < mat1.first_Dimension; i++) {
                mat1.new_Matrix[i] = new int[mat1.second_Dimension];
            }
            for(int i = 0; i < mat1.first_Dimension; i++)
                for(int j = 0; j < mat1.second_Dimension; j++)
                    cin>>mat1.new_Matrix[i][j];

            cout<<endl;
            cout<<"Please Enter Second Matrix Elements: \n";
            mat2.new_Matrix=new int*[mat1.first_Dimension];
            for (int i = 0; i < mat1.first_Dimension; i++) {
                mat2.new_Matrix[i] = new int[mat1.second_Dimension];
            }
            for(int i = 0; i < mat1.first_Dimension; i++)
                for(int j = 0; j < mat1.second_Dimension; j++)
                    cin>>mat2.new_Matrix[i][j];

            mat3=mat1-mat2;
            cout<<"The Result : \n";
            cout<<mat3;
            for(int i = 0; i < mat1.first_Dimension; i++)
                for(int j = 0; j < mat1.second_Dimension; j++)
                    cout<<mat3.new_Matrix[i][j];

        }
        if (Choice1=="3")
        {
            cin>>mat1;
            cin>>mat2;

            while(true)
            {
                if (mat1.second_Dimension==mat2.first_Dimension)
                    break;
                else
                {
                    cout<<"\"Error\" Your Dimensions Must be in ( AxB BxC ) Form \n\n";
                    cout<<"\" New Inputs \"\n";
                    cin>>mat1;
                    cin>>mat2;
                }
            }

            cout<<"Please Enter First Matrix Elements: \n";
            mat1.new_Matrix=new int*[mat1.first_Dimension];
            for (int i = 0; i < mat1.first_Dimension; i++) {
                mat1.new_Matrix[i] = new int[mat1.second_Dimension];
            }
            for(int i = 0; i < mat1.first_Dimension; i++)
                for(int j = 0; j < mat1.second_Dimension; j++)
                    cin>>mat1.new_Matrix[i][j];

            cout<<endl;

            cout<<"Please Enter Second Matrix Elements: \n";
            mat2.new_Matrix=new int*[mat2.first_Dimension];
            for (int i = 0; i < mat2.first_Dimension; i++) {
                mat2.new_Matrix[i] = new int[mat2.second_Dimension];
            }
            for(int i = 0; i < mat2.first_Dimension; i++)
                for(int j = 0; j < mat2.second_Dimension; j++)
                    cin>>mat2.new_Matrix[i][j];
            mat3=mat1*mat2;
            cout<<"The Result : \n";
            cout<<mat3;

        }
        if (Choice1=="4")
        {
            cin>>mat1;
            cout<<"Please Enter Matrix Elements: \n";
            mat1.new_Matrix=new int*[mat1.first_Dimension];
            for (int i = 0; i < mat1.first_Dimension; i++) {
                mat1.new_Matrix[i] = new int[mat1.second_Dimension];
            }

            for(int i = 0; i < mat1.first_Dimension; i++)
                for(int j = 0; j < mat1.second_Dimension; j++)
                    cin>>mat1.new_Matrix[i][j];
            mat2=mat1.transpose();
            cout<<"The New Matrix is: \n";
            cout<<mat2;

        }
        cout<<endl<<endl<<endl<<"Press 1 To Make Enter New Matrices or 0 To End Program: ";
        cin>>Choice2;
        while (Choice2!="1" && Choice2 !="0"){
            cout<<"Please Enter a Valid Choice: ";
            cin>>Choice2;
        }
        cout<<endl;
        if (Choice2=="0")
            break;
    }
}
