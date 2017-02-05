/*
 * Name: Soham Harnale
 * Roll No: SE202061
 */



#include<iostream>
using namespace std;

class cSmatrix
{
	int iMat[10][10];
	int iRow,iCol;
public:
	cSmatrix()													//default constructor
	{
		for(int i=0;i<iRow;i++)
		{
			for(int j=0;j<iCol;j++)
			{
				iMat[i][j]=0;
			}
		}
	}
	void vGetmatrix();
	void vCompact(cSmatrix);
	void vDisplay();
	cSmatrix vSimpleTranspose();
	void vFastTranspose();
	void vAddSmatrix(cSmatrix ,cSmatrix);
};

void cSmatrix::vGetmatrix()
{
	cout<<"Enter the number of rows & columns : "<<endl;
	cin>>iRow>>iCol;
		for(int i=0;i<iRow;i++)
		{
			for(int j=0;j<iCol;j++)
			{
			cout<<"Enter the number at position "<<"["<<""<<i<<"]"<<"["<<""<<j<<"]"<<endl;
			cin>>iMat[i][j];
			}
		}
}

void cSmatrix::vCompact(cSmatrix A)				//function for sparse representation
{
	iMat[0][0]=A.iRow;
	iMat[0][1]=A.iCol;
	int k=1;
	for(int i=0;i<A.iRow;i++)
	{
		for(int j=0;j<A.iCol;j++)
		{
			if(A.iMat[i][j]!=0)
			{
				iMat[k][0]=i;
				iMat[k][1]=j;
				iMat[k][2]=A.iMat[i][j];
				k++;
			}
		}
	}
	iMat[0][2]=k-1;
	iRow=k;
	iCol=3;

}

void cSmatrix::vDisplay()
{
	for(int i=0;i<iRow;i++)
	{
		for(int j=0;j<iCol;j++)
		{
			cout<<iMat[i][j]<<"\t";
		}
	cout<<"\n";
	}
}

cSmatrix cSmatrix::vSimpleTranspose()					//function for simple transpose of sparse matrix
{
	cSmatrix A;
	A.iMat[0][0]=iMat[0][0];
	A.iMat[0][1]=iMat[0][1];
	A.iMat[0][2]=iMat[0][2];
	int l=1;
	for(int i=0;i<iMat[0][1];i++)
	{
		for(int j=1;j<=iMat[0][2];j++)
		{
			if(iMat[j][1]==i)
			{
					A.iMat[l][0]=iMat[j][1];
					A.iMat[l][1]=iMat[j][0];
					A.iMat[l][2]=iMat[j][2];
					l++;
			}
		}
	}
	A.iRow=iRow;
	A.iCol=iCol;
	return A;
}

void cSmatrix::vAddSmatrix(cSmatrix X,cSmatrix Y)						//function to add two sparse matrices
{
	if(X.iMat[0][0]==Y.iMat[0][0] && X.iMat[0][1]==Y.iMat[0][1])
	{
		iMat[0][0]=X.iMat[0][0];
		iMat[0][1]=X.iMat[0][1];

		int i=1;int j=1;int k=1;
		while(i<=X.iMat[0][2] && j<=Y.iMat[0][2])
		{
			if(X.iMat[i][0]==Y.iMat[j][0])
			{
				if(X.iMat[i][1]==Y.iMat[j][1])
				{
					iMat[k][2]=X.iMat[i][2]+Y.iMat[j][2];
					iMat[k][0]=X.iMat[i][0];
					iMat[k][1]=X.iMat[i][1];
					i++;j++;k++;

				}
				else if(X.iMat[i][1]<Y.iMat[j][1])
				{
					iMat[k][2]=X.iMat[i][2];
					iMat[k][0]=X.iMat[i][0];
					iMat[k][1]=X.iMat[i][1];
					i++;k++;

				}
				else if(X.iMat[i][1]>Y.iMat[j][1])
				{
					iMat[k][2]=Y.iMat[j][2];
					iMat[k][0]=Y.iMat[j][0];
					iMat[k][1]=Y.iMat[j][1];
					j++;k++;

				}
			}
			else if(X.iMat[i][0]<Y.iMat[j][0])
			{
				iMat[k][2]=X.iMat[i][2];
				iMat[k][0]=X.iMat[i][0];
				iMat[k][1]=X.iMat[i][1];
				i++;k++;
			}
			else if(X.iMat[i][0]>Y.iMat[j][0])
			{
				iMat[k][2]=Y.iMat[j][2];
				iMat[k][0]=Y.iMat[j][0];
				iMat[k][1]=Y.iMat[j][1];
				j++;k++;
			}
		}
		while(i<=X.iMat[0][2] && j>Y.iMat[0][2])
		{
			iMat[k][2]=X.iMat[i][2];
			iMat[k][0]=X.iMat[i][0];
			iMat[k][1]=X.iMat[i][1];
			i++;k++;
		}
		while(j<=Y.iMat[0][2] && i>X.iMat[0][2] )
		{
			iMat[k][2]=Y.iMat[j][2];
			iMat[k][0]=Y.iMat[j][0];
			iMat[k][1]=Y.iMat[j][1];
			j++;k++;
		}
		iMat[0][2]=k-1;
		iRow=k;
		iCol=X.iCol;
		cout<<"Addition of sparse matrices is : "<<endl;
		vDisplay();
	}
	else
	{
		cout<<"Addition cannot be performed as dimensions are not equal !! "<<endl;
	}
}

void cSmatrix::vFastTranspose()						//function for fast transpose
{
	int t[10],ind[10],col;
	cSmatrix A;
	A.iMat[0][0]=iMat[0][0];
	A.iMat[0][1]=iMat[0][1];
	A.iMat[0][2]=iMat[0][2];

	for(int i=0;i<10;i++)
	{
		t[i]=0;
	}
	for(int i=1;i<iMat[0][2];i++)
	{
		col=iMat[i][1];
		t[col]++;
	}
		ind[0]=1;
	for(int i=1;i<=iMat[0][2];i++)
	{
		ind[i]=ind[i-1]+t[i-1];

	}
	for(int i=1;i<=iMat[0][2];i++)
	{
	int loc,j;
	col=iMat[i][1];

	loc=ind[col];
	ind[col]++ ;

	A.iMat[loc][0]=iMat[i][1];
	A.iMat[loc][1]=iMat[i][0];
	A.iMat[loc][2]=iMat[i][2];
	}

	A.iRow=iMat[0][2]+1;
	A.iCol=3;
	cout<<"Transpose of sparse matrix is : "<<endl;
	A.vDisplay();
}


int main()
{
	cSmatrix cM1 ,cM2 ,cS1,cS2 ,cT, cA;
	int choice;
	char opt;

	do{
	cout<<"Which operation would you like to perform ? "<<endl;
	cout<<"1.Sparse matrix representation\n2.Transpose of Sparse matrix\n3.Fast Transpose of matrix\n4.Addition of Sparse matrix"<<endl;
	cin>>choice;
	switch(choice)
	{
	case 1 :cM1.vGetmatrix();
			cout<<"Entered matrix is :"<<endl;
			cM1.vDisplay();
			cS1.vCompact(cM1);
			cout<<"The sparse matrix is : "<<endl;
			cS1.vDisplay();
			break;
	case 2 :cM1.vGetmatrix();
			cout<<"Entered matrix is :"<<endl;
			cM1.vDisplay();
			cS1.vCompact(cM1);
			cout<<"The sparse matrix is : "<<endl;
			cS1.vDisplay();
			cT=cS1.vSimpleTranspose();
			cout<<"Transpose of sparse matrix is : "<<endl;
			cT.vDisplay();
			break;
	case 3 :cM1.vGetmatrix();
			cout<<"Entered matrix is :"<<endl;
			cM1.vDisplay();
			cS1.vCompact(cM1);
			cout<<"The sparse matrix is : "<<endl;
			cS1.vDisplay();
			cS1.vFastTranspose();
			break;
	case 4 :cM1.vGetmatrix();
			cout<<"First matrix is :"<<endl;
			cM1.vDisplay();
			cS1.vCompact(cM1);
			cM2.vGetmatrix();
			cout<<"Second matrix is :"<<endl;
			cM2.vDisplay();
			cS2.vCompact(cM2);
			cout<<"The sparse representation of first matrix is : "<<endl;
			cS1.vDisplay();
			cout<<"The sparse representation of second matrix is : "<<endl;
			cS2.vDisplay();
			cA.vAddSmatrix(cS1,cS2);


			break;
	}
	cout<<"Do you want to run the program again ? (y/n)"<<endl;
	cin>>opt;
	}while(opt=='y');
return 0;
}

/* OUTPUT 
 
 Which operation would you like to perform ?
 1.Sparse matrix representation
 2.Transpose of Sparse matrix
 3.Fast Transpose of matrix
 4.Addition of Sparse matrix
 1
 Enter the number of rows & columns :
 2
 2
 Enter the number at position [0][0]
 1
 Enter the number at position [0][1]
 5
 Enter the number at position [1][0]
 3
 Enter the number at position [1][1]
 7
 Entered matrix is :
 1	5
 3	7
 The sparse matrix is :
 2	2	4
 0	0	1
 0	1	5
 1	0	3
 1	1	7
 Do you want to run the program again ? (y/n)
 y
 Which operation would you like to perform ?
 1.Sparse matrix representation
 2.Transpose of Sparse matrix
 3.Fast Transpose of matrix
 4.Addition of Sparse matrix
 2
 Enter the number of rows & columns :
 2
 2
 Enter the number at position [0][0]
 1
 Enter the number at position [0][1]
 3
 Enter the number at position [1][0]
 5
 Enter the number at position [1][1]
 7
 Entered matrix is :
 1	3
 5	7
 The sparse matrix is :
 2	2	4
 0	0	1
 0	1	3
 1	0	5
 1	1	7
 Transpose of sparse matrix is :
 2	2	4
 0	0	1
 0	1	5
 1	0	3
 1	1	7
 Do you want to run the program again ? (y/n)
 y
 Which operation would you like to perform ?
 1.Sparse matrix representation
 2.Transpose of Sparse matrix
 3.Fast Transpose of matrix
 4.Addition of Sparse matrix
 3
 Enter the number of rows & columns :
 2
 2
 Enter the number at position [0][0]
 1
 Enter the number at position [0][1]
 3
 Enter the number at position [1][0]
 5
 Enter the number at position [1][1]
 7
 Entered matrix is :
 1	3
 5	7
 The sparse matrix is :
 2	2	4
 0	0	1
 0	1	3
 1	0	5
 1	1	7
 Transpose of sparse matrix is :
 2	2	4
 0	0	1
 0	1	5
 1	0	3
 1	1	7
 Do you want to run the program again ? (y/n)
 y
 Which operation would you like to perform ?
 1.Sparse matrix representation
 2.Transpose of Sparse matrix
 3.Fast Transpose of matrix
 4.Addition of Sparse matrix
 4
 Enter the number of rows & columns :
 2
 2
 Enter the number at position [0][0]
 1
 Enter the number at position [0][1]
 3
 Enter the number at position [1][0]
 5
 Enter the number at position [1][1]
 7
 First matrix is :
 1	3
 5	7
 Enter the number of rows & columns :
 2
 2
 Enter the number at position [0][0]
 3
 Enter the number at position [0][1]
 8
 Enter the number at position [1][0]
 4
 Enter the number at position [1][1]
 7
 Second matrix is :
 3	8
 4	7
 The sparse representation of first matrix is :
 2	2	4
 0	0	1
 0	1	3
 1	0	5
 1	1	7
 The sparse representation of second matrix is :
 2	2	4
 0	0	3
 0	1	8
 1	0	4
 1	1	7
 Addition of sparse matrices is :
 2	2	4	
 0	0	4	
 0	1	11	
 1	0	9	
 1	1	14	
 Do you want to run the program again ? (y/n)
 n
 Program ended with exit code: 0
 
 */
