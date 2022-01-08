// C++ Program to Inverse a 2x2 or 3x3 Matrix
#include<iostream>
#include <iomanip> //for setting float precision
//using namespace std;
using std::cout;
using std::cin;
using std::setprecision;

int i=0,j=0,N=3;
float matOrderSelect, determinant, inverse2[2][2]={0}, tempmatrix[2][2];

class Matrix
{
  private:
    /* data */
  public:
    float **enterMatrix(float matOrderSelect)
    {
          int i=matOrderSelect, j=matOrderSelect; 
          float **mat1= new float*[N];
          cout<<"\t\t | Matrix Inversion of "<<i<<"X"<<j<<" | \t\t\n";
          cout << "Enter Elements of "<<i<<"X"<<j<<" Matrix: \n";

          for(i=0; i < matOrderSelect; i++)
          {
              mat1[i]= new float[N];
              for(j=0; j < matOrderSelect; j++ ) 
              {
                cout <<"Matrix["<<i<<"]["<<j<<"]:";
                cin>>mat1[i][j];
              }
          }
          return mat1;
    }
    void printMatrix(float **mat1, float matOrderSelect)
    {
      cout<<"\v";
      cout<<"Given "<<matOrderSelect<<"X"<<matOrderSelect<<" Matrix: ";

      for(i=0; i < matOrderSelect; i++)
      {
        cout<<"\n";
        for(j=0; j < matOrderSelect; j++ ) 
          {
            cout <<mat1[i][j];
            if((j+1)!=matOrderSelect)
            {
              cout<<", ";
            }
            else
            {
              cout<<" ";
            }
          }
        cout<<"";
      }
    }

// void Matrix::printMatrix(float**mat1, float matOrderSelect)
// {
//   cout<<"\v";
//   cout<<"Given "<<matOrderSelect<<"X"<<matOrderSelect<<" Matrix: ";

//   for(i=0; i < matOrderSelect; i++)
//   {
//     cout<<"\n";
//     for(j=0; j < matOrderSelect; j++ ) 
//       {
//         cout <<mat1[i][j];
//         if((j+1)!=matOrderSelect)
//         {
//           cout<<", ";
//         }
//         else
//         {
//           cout<<" ";
//         }
//       }
//     cout<<"";
//   }

};

class Matrix2D : public Matrix
{       
  private: 
        
  public:
    float **InverseOf2(float **givenMatrix)
    {
        tempmatrix[0][0]=givenMatrix[0][0];
        givenMatrix[0][0]=givenMatrix[1][1];
        givenMatrix[1][1]=tempmatrix[0][0];
              
        givenMatrix[0][1]=givenMatrix[0][1]-(2*givenMatrix[0][1]);
        givenMatrix[1][0]=givenMatrix[1][0]-(2*givenMatrix[1][0]);
            
        cout<<'\n'<<"Inverse matrix: \n";
        for(i=0;i<matOrderSelect;i++) 
        {
          cout<<'\n';
          for(j=0;j<matOrderSelect;j++) 
          {
            inverse2[i][j]= (givenMatrix[i][j]/determinant);
            cout<<inverse2[i][j]<<setprecision(2);

            if((j+1)!=matOrderSelect)
            {
              cout<<", ";
            }
            else
            {
              cout<<" ";
            }
          }
        }    
    }
  
    int Determinant2D(int matorderselect, float **givenMatrix)
    {
      if(matOrderSelect==2)
      {
        return (givenMatrix[0][0] * givenMatrix[1][1])-(givenMatrix[0][1] * givenMatrix[1][0]);
      }
    }
};

class Matrix3D : public Matrix
{       
  private: 
        
  public:
    int Determinant3D(int matorderselect, float **givenMatrix)
    {
      if(matOrderSelect==3)
      {
        return (givenMatrix[0][0] * (givenMatrix[1][1] * givenMatrix[2][2] - givenMatrix[2][1] * givenMatrix[1][2]) 
                -givenMatrix[0][1] * (givenMatrix[1][0] * givenMatrix[2][2] - givenMatrix[2][0] * givenMatrix[1][2]) 
                +givenMatrix[0][2] * (givenMatrix[1][0] * givenMatrix[2][1] - givenMatrix[2][0] * givenMatrix[1][1]));
      }
    }

    float Cofactor3D(int matorderselect, float **givenMatrix)
    {
      float Cofactors[3][3] = {0};

      int i, j = 0;

      Cofactors[0][0] = givenMatrix[1][1]*givenMatrix[2][2]-givenMatrix[1][2]*givenMatrix[2][1];               
      Cofactors[0][1] = -1*(givenMatrix[1][0]*givenMatrix[2][2]-givenMatrix[1][2]*givenMatrix[2][0]);
      Cofactors[0][2] = givenMatrix[1][0]*givenMatrix[2][1]-givenMatrix[1][1]*givenMatrix[2][0];
      Cofactors[1][0] = -1*(givenMatrix[0][1]*givenMatrix[2][2]-givenMatrix[2][1]*givenMatrix[0][2]);
      Cofactors[1][1] = givenMatrix[0][0]*givenMatrix[2][2]-givenMatrix[0][2]*givenMatrix[2][0];
      Cofactors[1][2] = -1*(givenMatrix[0][0]*givenMatrix[2][1]-givenMatrix[0][1]*givenMatrix[2][0]);
      Cofactors[2][0] = givenMatrix[0][1]*givenMatrix[1][2]-givenMatrix[0][2]*givenMatrix[1][1];
      Cofactors[2][1] = -1*(givenMatrix[0][0]*givenMatrix[1][2]-givenMatrix[0][2]*givenMatrix[1][0]);
      Cofactors[2][2] = givenMatrix[0][0]*givenMatrix[1][1]-givenMatrix[0][1]*givenMatrix[1][0]; 

      cout << "==============\n Cofactors \n==============\n";
      for(i=0;i<matOrderSelect;i++)
      {
        for(j=0;j<matOrderSelect;j++)
        {
          cout <<"Cofactor["<<i<<"]" << "[" <<j<< "] = "<< Cofactors[i][j]<<" ";
        }
          printf("\n");
      }
    }

};

int main()
{
  float **givenMatrix;
  //Matrix one;
  Matrix2D Two;
  Matrix3D Three;
  cout<< "\n\n==============Select Matrix Order to inverse!==================\n\n";
  choice:
  cout<< "\nPress 1 to enter a custom order of Square Matrix.(Doesn't work yet!) \nPress 2 for 2x2 Matrix inversion.\nPress 3 for 3x3 Matrix Inversion.\n"; 
  cin>>matOrderSelect;
    
  if(matOrderSelect!=2 && matOrderSelect!=3)
  {
    cout<<"Invalid Choice! Select one of the available Option.";
    goto choice;
  }
  else
  {
    Matrix one;
    givenMatrix = Two.enterMatrix(matOrderSelect);
    Two.printMatrix(givenMatrix, matOrderSelect);

    if(matOrderSelect==2)
    {
      determinant= Two.Determinant2D(matOrderSelect, givenMatrix);
      cout<<"\nDeterminant: "<<determinant;

      if(determinant==0)
      {
        cout<<"\nDeterminant is 0, Matrix's inverse doesn't Exit!\n";
      }
      else
      {
        cout<<"\nDeterminant is not 0, Matrix Inverse Exist\n";
        Two.InverseOf2(givenMatrix);
      }  
      
    }
      
    if(matOrderSelect==3)
    {
      determinant = Three.Determinant3D(matOrderSelect, givenMatrix);
      cout<<"\nDeterminant: "<<determinant;
      
      if(determinant==0)
      {
        cout<<"\nDeterminant is 0, Matrix's inverse doesn't Exit!\n";
      }
      else
      {
        cout<<"\nDeterminant is not 0, Matrix Inverse Exist\n";
        Three.Cofactor3D(matOrderSelect, givenMatrix);
      }  
    }
  }
  return 0;
}