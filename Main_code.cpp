// C++ Program to Inverse a 2x2 or 3x3 Matrix
#include<iostream>
//using namespace std;
using std::cout;
using std::cin;

void enterMatrix(int matOrderSelect)
{
    {
        int i=matOrderSelect, j=matOrderSelect; 
        int mat1[matOrderSelect][matOrderSelect];
        cout<<"\t\t | Matrix Inversion of "<<i<<"X"<<j<<" | \t\t\n";
        
        cout << "Enter Elements of "<<i<<"X"<<j<<" Matrix: \n";

        for(i=0; i < matOrderSelect; i++)
        {
            for(j=0; j < matOrderSelect; j++ ) 
            {
              cout <<"Matrix["<<i<<"]["<<j<<"]:";
              cin >> mat1[i][j];

            }
        }

        cout<<"\v";
        cout<<"Given "<<i<<"X"<<j<<" Matrix: ";

        for(i=0; i < matOrderSelect; i++)
        {
          cout<<'\n';
          for(j=0; j < matOrderSelect; j++ ) 
            {
              cout <<mat1[i][j]<<" ";
            }
        }

    }

}
int main()
{
    int matOrderSelect, i=0 ,j=0, inversed[i][j], determinant, adjoint, minor[i][i],cofactors[i][j];
    cout<< "Select Matrix Order to inverse!\n";
    cout<< "Press 2 for 2x2 Matrix inversion.\nPress 3 for 3x3 Matrix Inversion.";
    choice:
    cin>>matOrderSelect;

    
    if(matOrderSelect!=2 && matOrderSelect!=3)
    {
        cout<<"Invalid Choice! Select one of the available Option.";
        goto choice;
    }
    else
    {
      enterMatrix(matOrderSelect);
    }
    return 0;
}
