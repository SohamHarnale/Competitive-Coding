/*
 * Name: Soham Harnale
 * Roll No: SE202061
 */





#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class cSort
{
    float fArr[20];
public:
    int iSize;
    void vInsertionSort();
    void vShellSort();
    void vAccept();
    void vDisplay();
};

void cSort::vInsertionSort()
{
    int i,j;
    float element;
    for(i=0;i<iSize;i++)
    {
        element = fArr[i];
        j=i;

        while(j>0 && fArr[j-1]>element)
        {
            fArr[j] = fArr[j-1];
            j--;
        }

        fArr[j] = element;

//        if(i<5)
        {
            cout<<"Pass "<<i+1<<":: " ;
            vDisplay();
            cout<<endl;
        }
    }
}

void cSort::vShellSort()
{
    int d,flag,j,k=0;
    float temp;
    d=iSize;

    while(d>0)
    {
        d=d/2;
        flag=1;

        while(flag==1)
        {
            flag=0;
            j=iSize-d;

            for(int i=0;i<j;i++)
            {
                if(fArr[i]>fArr[i+d])
                {
                    temp = fArr[i];
                    fArr[i]=fArr[i+d];
                    fArr[i+d]=temp;

                    flag=1;
                }
            }
            cout<<"Pass "<<k+1<<" is \n";
            for(int i=0;i<iSize;i++)
            	cout<<fArr[i]<<"  ";
            cout<<endl;
            k++;
        }
    }
}

void cSort::vAccept()
{
    for(int i=0;i<iSize;i++)
        {
            cin>>fArr[i];
        }

}

void cSort::vDisplay()
{
    for(int i=0;i<iSize;i++)
        {
            cout<<fArr[i]<<" ";
        }
}

int main()
{
    int n,size;
    char ch='y';
    cSort s;
    while(ch=='y')
    {
		cout<<"1. Insertion Sort"<<endl;
		cout<<"2. Shell Sort"<<endl;
		cout<<"Enter choice - ";
		cin>>n;
		switch(n)
		{
		case 1: cout<<"Enter size of array - ";
				cin>>size;
				s.iSize=size;
				cout<<"Enter elements of array"<<endl;
				s.vAccept();
				cout<<endl;
				cout<<"The array entered is - "<<endl;
				s.vDisplay();
				cout<<endl;
				s.vInsertionSort();
				cout<<"Array after sorting is - "<<endl;
				s.vDisplay();
				break;
		case 2: cout<<"Enter size of array - ";
				cin>>size;
				s.iSize=size;
				cout<<"Enter elements of array"<<endl;
				s.vAccept();
				cout<<endl;
				cout<<"The array entered is - "<<endl;
				s.vDisplay();
				cout<<endl;
				s.vShellSort();
				cout<<"Array after sorting is - "<<endl;
				s.vDisplay();
				break;
		default:cout<<"Invalid choice!!!"<<endl;
				break;
		}
		cout<<endl;
		cout<<"Do you wish to continue(y/n)"<<endl;
		cin>>ch;
    }
    return 0;
}

/****************************************************************************************
OUTPUT ->

1. Insertion Sort
2. Shell Sort
Enter choice - 1
Enter size of array - 8
Enter elements of array
12.2
2.3
13.32
13.31
15.6
67.08
4.56
6.54

The array entered is -
12.2 2.3 13.32 13.31 15.6 67.08 4.56 6.54
Pass 1:: 12.2 2.3 13.32 13.31 15.6 67.08 4.56 6.54
Pass 2:: 2.3 12.2 13.32 13.31 15.6 67.08 4.56 6.54
Pass 3:: 2.3 12.2 13.32 13.31 15.6 67.08 4.56 6.54
Pass 4:: 2.3 12.2 13.31 13.32 15.6 67.08 4.56 6.54
Pass 5:: 2.3 12.2 13.31 13.32 15.6 67.08 4.56 6.54
Pass 6:: 2.3 12.2 13.31 13.32 15.6 67.08 4.56 6.54
Pass 7:: 2.3 4.56 12.2 13.31 13.32 15.6 67.08 6.54
Pass 8:: 2.3 4.56 6.54 12.2 13.31 13.32 15.6 67.08
Array after sorting is -
2.3 4.56 6.54 12.2 13.31 13.32 15.6 67.08
Do you wish to continue(y/n)
y
1. Insertion Sort
2. Shell Sort
Enter choice - 2
Enter size of array - 6
Enter elements of array
1.2
12.23
2.3
23.34
3.4
34.56

The array entered is -
1.2 12.23 2.3 23.34 3.4 34.56
Pass 1 is
1.2  3.4  2.3  23.34  12.23  34.56
Pass 2 is
1.2  3.4  2.3  23.34  12.23  34.56
Pass 3 is
1.2  2.3  3.4  12.23  23.34  34.56
Pass 4 is
1.2  2.3  3.4  12.23  23.34  34.56
Pass 5 is
1.2  2.3  3.4  12.23  23.34  34.56
Array after sorting is -
1.2 2.3 3.4 12.23 23.34 34.56
Do you wish to continue(y/n)
n


****************************************************************************************/
