//============================================================================
// Name        : Assignment .cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Program to make a database of the students of the class
#include <iostream>			// header file
#include<stdio.h>
using namespace std;
class student					// class declaration
{
    char *name,*address,*div ,*bloodg;		//data members
    int dob,rollno,mobno;
    static int count;			// static variable
public:
    
    student();
    student(student &s);
    void vmodify(int n);
    int  vsearch(int n, int);
    void vgetdata();
    void vmod();
    void vadd(int & );
    void vdisplay();
    void vdelete(int &);
    friend class search;
    ~student();
    void vincrement()				//inline function
    {
        count++;
    };
};

int student ::count;
student::student()			//default constructor
{
    name=new char [30];
    address=new char [30];
    div=new char [30];
    bloodg=new char [30];
    mobno=0;
    rollno=0;
    dob=0;
}//end of constructor


student ::student(student &s)
{	name=s.name;
    dob=s.dob;
    rollno=s.rollno;
    bloodg=s.bloodg;
    div=s.div;
    mobno=s.mobno;
    address=s.address;
}


student ::~student()
{
    delete name;
    delete address;
    delete div;
    delete bloodg;
    
}
void student::vgetdata()	// for accepting data
{
    cout<<"\n Enter the name of the student";
    cin>>name;
    cout<<"\n Enter the Date of Birth ";
    cin>>dob;
    cout<<"\n Enter the roll no";
    cin>>rollno;
    cout<<endl<<"Enter the address"<<endl;
    cin>>address;
    cout<<"Enter the mobile no"<<endl;
    cin>>mobno;
    cout<<"Enter the division of the student "<<endl;
    cin>>div;
    cout<<"Enter the Blood group "<<endl;
    cin>>bloodg;
} // end of function to get data


void student::vdisplay()		//function to display data
{	cout<<"The name is  "<<name<<endl;
    cout<<"The Address is  "<<address<<endl;
    cout<<"The date of birth is  "<<dob<<endl;
    cout<<"The roll no is  "<<rollno<<endl;
    cout<<"The mobile no  "<<mobno<<endl;
    cout<<"The division is  " <<div<<endl;
    cout<<"THe Blood Group  "<<bloodg<<endl;
    cout<<"-----------------"<<endl;
}// display function


/*
 * int  student :: vsearch(int n, int rno )
	{
 int flag =0,b=0;
 for(int i=0;i<n;i++)
 {
 if(this [i].rollno==rno)
 {	flag=1;
 break;
 b=i;
 }
 }
 if (flag==1)
 {	cout<<"The record of the student is found at"<<count<<endl;
 this[b].vdisplay();
 }
 else
 {	cout<<"There is no such record"<<endl;
 
 }
 return flag;
	}// search function	`*/


void student ::vadd(int &n)			// to add no of entries
{	int n1;
    cout<<"Enter the no of entries to be added "<<endl;
    cin>>n1;
    cout<<"Enter the details to be added "<<endl;
    for(int i=n;i<n+n1;i++)
    {
        this[i].vgetdata();
        this[i].vincrement();		// to increase the value of the static variable
        
    }
    for(int i=n;i<n1;i++)
        this[i].vdisplay();
    n+=n1;
    cout<<"The new number of records in database are "<<count; // to display the total no of students
}// end of add function



void student :: vmodify(int n) // to Modify the given record
{
    int rno,flag=0;;
    cout<<"Enter the roll no of record to be modified";
    cin>>rno;
				for(int i=0;i<n;i++)
                {if(rno==this[i].rollno)
                {	flag=1;
                    cout<<"This record can be modified"<<endl;
                    this [i].vmod();
                    this[i].vdisplay();
                    break;
                }
                }
    if(flag==0)
        cout<<"This record is not found !! Enter a valid record"<<endl;
    
}// end of modify function




void student :: vdelete(int &n)	// to delete the entry
{	int rno,flag=0,b;
    cout<<"Enter the  roll number of the record to be deleted"<<endl;
    cin>>rno;
				for(int i=0;i<n;i++)
                {		if(rno==this[i].rollno)
                {	b=i;
                    delete this[i].address;
                    flag=1;
                    cout<<"The record can be deleted "<<endl;
                    break;
                }
                }
    if(flag==0)
        cout<<"\n THE RECORD CANNOT BE DELETED"<<endl;
    
				if(flag==1)
                {	this [b].vdisplay();
                    
                    for(int i=b;i<n;i++)
                    {
                        this[b]=this[b+1];
                    }
                    n--;
                    count--;
                    cout<<"The number of remaining students are"<<" "<<count<<endl;
                }
}// end of delete function

// friend class definition
class search
{
public:
    void check(student *s, int n);
    
};

void search :: check(student *s, int n)
{
    int flag=0;
    int rno,i;
    cout<<"Enter the roll no to be searched";
    cin>>rno;
    for(i=0;i<n;i++)
    {
        if(s[i].rollno==rno)
        {	flag=1;
            break;
        }
    }
    if (flag==1)
    {	cout<<"The record of the student is found"<<endl;
        s[i].vdisplay();
    }
    
    if (flag==0)
    {	cout<<"There is no such record"<<endl;
        
    }
    
}// end of friend class search function

int main() {
    student *s;
    search *s1;
    s1=new search;		//dynamic initialisation
    int n,ch;
    char x;
    cout<<"\nEnter the no of students whose database is to be entered"<<endl;
    cin>>n;
    s=new student[n+10];
    for(int i=0;i<n;i++)		// loop to accept the details  of students
    {	s[i].vgetdata();
        s->vincrement();
    }
    do
    {	cout<<"\n----- MENU-----"<<endl;
        cout<<"1.Search"<<endl;
        cout<<"2.Addition"<<endl;
        cout<<"3.Modify"<<endl;
        cout<<"4.Delete"<<endl;
        cin>>ch;
        switch(ch)				// switch case
        {
            case 1 :
                s1->check(s,n);
                //s->vsearch(n, rno);
                break;
            case 2 :  s->vadd(n);
                break;
            case 3:  s->vmodify(n);
                break;
            case 4: s->vdelete(n);
                break;
        }
        cout<<"Do you want to repeat the operations(y/n)"<<endl;
        cin>>x;
    }while(x=='y'||x=='Y');
    
    
    delete s1;
    delete s;
    return 0;
}// end of main function
