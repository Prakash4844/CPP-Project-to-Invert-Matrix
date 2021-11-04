// C++ Program to Inverse a 2x2 or 3x3 Matrix
#include<iostream>
#include <iomanip> //for setting float precision
//using namespace std;
using std::cout;
using std::cin;
using std::setprecision;

float **enterMatrix(float matOrderSelect);
void printMatrix(float **mat1, float matOrderSelect);
float **InverseOf2(float **givenMatrix);

int i=0,j=0,N=3;
float matOrderSelect, determinant, inverse2[2][2]={0}, tempmatrix[2][2];

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

void printMatrix(float**mat1, float matOrderSelect)
{
  cout<<"\v";
  cout<<"Given "<<matOrderSelect<<"X"<<matOrderSelect<<" Matrix: ";

  for(i=0; i < matOrderSelect; i++)
  {
    cout<<"\n";
    for(j=0; j < matOrderSelect; j++ ) 
    {
      cout <<mat1[i][j]<<" ";
    }
    cout<<"";
  }

}

float **InverseOf2(float **givenMatrix)
{
  if(determinant==0)
  {
    cout<<"\nDeterminant is 0, Matrix's inverse doesn't Exist!\n";
  }
  else
  {
    cout<<"\nDeterminant is not 0, Matrix Inverse Exist\n";

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
      cout<<inverse2[i][j]<<setprecision(2)<<" ";
      }
    }
  }     
}

int main()
{
  float **givenMatrix;

  cout<< "\n\n==============Select Matrix Order to inverse!==================\n\n";
  choice:
  cout<< "\nPress 1 to enter a custom order of Square Matrix.(Doesn't work yet!) \nPress 2 for 2x2 Matrix inversion.\nPress 3 for 3x3 Matrix Inversion."; 
  cin>>matOrderSelect;
    
  if(matOrderSelect!=2 && matOrderSelect!=3)
  {
    cout<<"Invalid Choice! Select one of the available Option.";
    goto choice;
  }
  else
  {
    givenMatrix = enterMatrix(matOrderSelect);
    printMatrix(givenMatrix, matOrderSelect);

    if(matOrderSelect==2)
    {
      determinant=(givenMatrix[0][0] * givenMatrix[1][1])-(givenMatrix[0][1] * givenMatrix[1][0]);
      cout<<"\nDeterminant: "<<determinant;
      InverseOf2(givenMatrix);
        
    }
      
    if(matOrderSelect==3)
    {
          
      determinant = givenMatrix[0][0] * (givenMatrix[1][1] * givenMatrix[2][2] - givenMatrix[2][1] * givenMatrix[1][2]) 
                    -givenMatrix[0][1] * (givenMatrix[1][0] * givenMatrix[2][2] - givenMatrix[2][0] * givenMatrix[1][2]) 
                    +givenMatrix[0][2] * (givenMatrix[1][0] * givenMatrix[2][1] - givenMatrix[2][0] * givenMatrix[1][1]);
                     
      cout<<"\nDeterminant: "<<determinant;
      
      if(determinant==0)
      {
        cout<<"\nDeterminant is 0, Matrix's inverse doesn't Exit!\n";
      }
      else
      {
        cout<<"\nDeterminant is not 0, Matrix Inverse Exist\n";
      }  
    }
  }
  
  return 0;
}