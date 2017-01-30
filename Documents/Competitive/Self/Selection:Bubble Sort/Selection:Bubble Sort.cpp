/*
 * Name: Soham Harnale
 * Roll No: SE202061
 */



#include<iostream>
using namespace std;
class Sorting
{
	float *f;
	int size;
public:
	void vAccept();
	void vDisplay();
	void vSelection();
	void vBubbleSort();
	void vTop5();
};
void Sorting::vAccept()
{
	cout<<"Enter the total no. of students present:"<<endl;
	cin>>size;
	f=new float[size];
	cout<<"Enter the final marks of all students"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>f[i];
	}
}
void Sorting::vDisplay()
{
	for(int i=0;i<size;i++)
	{
		cout<<f[i]<<"\t";
	}
	cout<<endl;
}
void Sorting::vBubbleSort()
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(f[j]>f[j+1])
			{
				f[j]=f[j]+f[j+1];
				f[j+1]=f[j]-f[j+1];
				f[j]=f[j]-f[j+1];
			}
		}
	}
}
void Sorting::vSelection()
{
	int iLow,k;
	for(int i=0;i<size;i++)
	{
		iLow=f[i];
		k=i;
		for(int j=i+1;j<size;j++)
		{
			if(f[j]<iLow)
			{
				iLow=f[j];
				k=j;
			}
		}
		if(k!=i)
		{
			f[i]=f[i]+f[k];
			f[k]=f[i]-f[k];
			f[i]=f[i]-f[k];

		}
	}
}
void Sorting::vTop5()
{
	vAccept();
	vSelection();
	cout<<"Top marks scored in class are"<<endl;
	for(int i=size-1;i>=size-6&&i>=0;i--)
	{
		cout<<f[i]<<"\t";
	}cout<<endl;
}
int main()
{
	Sorting c1;
	int iChoice;
	char cChoice;
	do{
	cout<<"Enter Which of the following operations you want to perform"<<endl;
	cout<<"1. Bubble Sort \n2. Selection Sort"<<endl;
	cout<<"3. Top Marks"<<endl;
	cin>>iChoice;
		switch(iChoice)
		{
			case 1:
				c1.vAccept();
				cout<<"Marks of students present in classroom are:"<<endl;
				c1.vDisplay();
				c1.vBubbleSort();
				cout<<"List of Marks after sorting is:"<<endl;
				c1.vDisplay();
			break;
			case 2:
				c1.vAccept();
				cout<<"Marks of students present in classroom are:"<<endl;
				c1.vDisplay();
				c1.vSelection();
				cout<<"List of Marks after sorting is:"<<endl;
				c1.vDisplay();
			break;
			case 3:
				c1.vTop5();
			break;
		}
		cout<<"Do you want to continue(Y/N)"<<endl;
		cin>>cChoice;
	}while(cChoice=='y'||cChoice=='Y');
	return 0;
}

/* OUTPUT 
 
 Enter Which of the following operations you want to perform
 1. Bubble Sort
 2. Selection Sort
 3. Top Marks
 1
 Enter the total no. of students present:
 5
 Enter the final marks of all students
 23
 54
 12
 87
 90
 Marks of students present in classroom are:
 23	54	12	87	90
 List of Marks after sorting is:
 12	23	54	87	90
 Do you want to continue(Y/N)
 y
 Enter Which of the following operations you want to perform
 1. Bubble Sort
 2. Selection Sort
 3. Top Marks
 2
 Enter the total no. of students present:
 5
 Enter the final marks of all students
 12
 32
 43
 15
 36
 Marks of students present in classroom are:
 12	32	43	15	36
 List of Marks after sorting is:
 12	15	32	36	43
 Do you want to continue(Y/N)
 y
 Enter Which of the following operations you want to perform
 1. Bubble Sort
 2. Selection Sort
 3. Top Marks
 3
 Enter the total no. of students present:
 4
 Enter the final marks of all students
 12
 65
 78
 90
 Top marks scored in class are
 90	78	65	12
 Do you want to continue(Y/N)
 n
 Program ended with exit code: 0 */



