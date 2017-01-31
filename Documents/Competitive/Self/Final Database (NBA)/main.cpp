/*
 * singly.cpp
 *
 *  Created on: 12-Aug-2016
 *      Author: student
 */


#include<iostream>
using namespace std;
class list
{
    char data[20];
    long int roll;
    list *next;
    friend class sll;
};
class sll
{
    list *head;list *curr;
public:
    sll();
    void display();
    void create();
    int len();
    void insert_by_pos();
    void delete_by_pos();
    void concat();
};
sll::sll()
{
    head=new list;
    head->next=NULL;
    head->data[0]={'0'};
    head->roll=0;
}
void sll::create()
{
    list *temp;
    char ans;
    temp=head;
    do
    {
        curr=new list;
        cout<<"\n Enter the name of the member : ";
        cin>>curr->data;
        cout<<"\n Enter the prn no of the member : ";
        cin>>curr->roll;
        curr->next=NULL;
        temp->next=curr;
        temp=curr;
        cout<<"\n Do you want to add next element [y/n] \n";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
    curr->next=NULL;
}
int sll::len()
{
    int c=0;
    curr=head->next;
    while(curr!=NULL)
    {
        curr=curr->next;
        c++;
    }
    return c;
}
void sll::display()
{
    list *temp=head;
    head->roll=len();
    cout<<"Head Node Details are :\n";
    cout<<"Total nodes is the list are \t Head node address \t First node address"<<endl;
    cout<<head->roll<<"\t\t\t\t  ";
    cout<<head<<"\t\t  ";
    curr=head->next;
    cout<<curr<<"\t\t  ";
    cout<<endl;
    cout<<"Name of the member \t PRN no. \t Designation \t   Previous node address \t Current node address \t Next node address ";
    cout<<endl;
    while(curr!=NULL)
    {
        cout<<curr->data<<"\t\t\t  ";
        cout<<curr->roll<<"\t\t  ";
        if(curr==head->next)
        {
            cout<<"President"<<"\t\t  ";
            cout<<head<<"\t\t  ";
            cout<<curr<<"\t\t  ";
        }
        else if(curr->next==NULL)
        {
            cout<<"Secretary"<<"\t\t  ";
            cout<<temp<<"\t\t  ";
            cout<<curr<<"\t\t  ";
        }
        else
        {
            cout<<"Member"<<"\t\t  ";
            cout<<temp<<"\t\t  ";
            cout<<curr<<"\t\t  ";
        }
        temp=curr;
        curr=curr->next;
        cout<<curr<<"\t\t  ";
        cout<<endl;
    }
    cout<<endl;
}
void sll::insert_by_pos()
{
    list *prev;
    list *temp;
    int pos;
    temp=new list;
    temp->next=NULL;
    cout<<"\nEnter the position where the data is to be inserted: ";
    cin>>pos;
    if(pos<=len()+1&&pos>-1)
    {
        cout<<"\nEnter the name of the member to be inserted: ";
        cin>>temp->data;
        cout<<"\n Enter the prn no of the member to be inserted : ";
        cin>>temp->roll;
        cout<<"\n Original list is\n";display();
        curr=head->next;
        int i=1;
        prev=head;
        while(i<pos)
        {
            prev=curr;
            curr=curr->next;
            i++;
        }
        prev->next=temp;
        temp->next=curr;
        cout<<"List with the appended data is \n";
        display();
    }
    else
        cout<<"Invalid positon\n";
}
void sll::delete_by_pos()
{
    cout<<"\nEnter the position to delete: ";
    int pos,i=1;
    cin>>pos;
    if(pos<=len()&&pos>0)
    {
        cout<<"\n Original list is\n";display();
        list *prev;
        prev=head;
        curr=head->next;
        while(i<pos)
        {
            prev=curr;
            curr=curr->next;
            i++;
        }
        prev->next=curr->next;
        cout<<"List with deleted element is\n";display();
    }
    else
        cout<<"Invalid position\n";
}
void sll::concat()
{
    sll l2;
    cout<<"\nEnter the details of the 2nd list\n";
    l2.create();
    l2.display();
    cout<<"\nOriginal list is\n";
    this->display();
    curr=head->next;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=l2.head->next;
    cout<<"\nConcatenated list is\n";
    display();
}
int main()
{
    sll l1;
    int n;
    char choice;
    l1.create();
    l1.len();
    cout<<"Entered list is\n";
    l1.display();
    do
    {
        cout<<"1.Insert by position\n";
        cout<<"2.Total no. of members in the list\n";
        cout<<"3.Delete by position\n";
        cout<<"4.Concatenation of two lists\n";
        cout<<"\nEnter your choice: ";
        cin>>n;
        switch(n)
        {
            case 1:l1.insert_by_pos();break;
            case 2:cout<<"\nTotal no. of members are\n: "<<l1.len()<<endl;break;
            case 3:l1.delete_by_pos();break;
            case 4:l1.concat();break;
            default:cout<<"Invalid choice\n";
        }
        cout<<"Do you want to continue :[y/n]";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    return  0;
}



/*	OUTPUT
 
 Enter the name of the member : Yash
 
 Enter the prn no of the member : 15001
 
 Do you want to add next element [y/n]
 y
 
 Enter the name of the member : Tanmay
 
 Enter the prn no of the member : 15002
 
 Do you want to add next element [y/n]
 y
 
 Enter the name of the member : Rishi
 
 Enter the prn no of the member : 15003
 
 Do you want to add next element [y/n]
 n
 Entered list is
 Head Node Details are :
 Total nodes is the list are 	 Head node address 	 First node address
 3				  0x17c9010		  0x17c9040
 Name of the member 	 PRN no. 	 Designation 	   Previous node address 	 Current node address 	 Next node address
 Yash			  15001		  President		  0x17c9010		  0x17c9040		  0x17c9070
 Tanmay			  15002		  Member		  0x17c9040		  0x17c9070		  0x17c90a0
 Rishi			  15003		  Secretary		  0x17c9070		  0x17c90a0		  0
 
 1.Insert by position
 2.Total no. of members in the list
 3.Delete by position
 4.Concatenation of two lists
 
 Enter your choice: 1
 
 Enter the position where the data is to be inserted: 4
 
 Enter the name of the member to be inserted: Shivam
 
 Enter the prn no of the member to be inserted : 15004
 
 Original list is
 Head Node Details are :
 Total nodes is the list are 	 Head node address 	 First node address
 3				  0x17c9010		  0x17c9040
 Name of the member 	 PRN no. 	 Designation 	   Previous node address 	 Current node address 	 Next node address
 Yash			  15001		  President		  0x17c9010		  0x17c9040		  0x17c9070
 Tanmay			  15002		  Member		  0x17c9040		  0x17c9070		  0x17c90a0
 Rishi			  15003		  Secretary		  0x17c9070		  0x17c90a0		  0
 
 List with the appended data is
 Head Node Details are :
 Total nodes is the list are 	 Head node address 	 First node address
 4				  0x17c9010		  0x17c9040
 Name of the member 	 PRN no. 	 Designation 	   Previous node address 	 Current node address 	 Next node address
 Yash			  15001		  President		  0x17c9010		  0x17c9040		  0x17c9070
 Tanmay			  15002		  Member		  0x17c9040		  0x17c9070		  0x17c90a0
 Rishi			  15003		  Member		  0x17c9070		  0x17c90a0		  0x17c90d0
 Shivam			  15004		  Secretary		  0x17c90a0		  0x17c90d0		  0
 
 Do you want to continue :[y/n]y
 1.Insert by position
 2.Total no. of members in the list
 3.Delete by position
 4.Concatenation of two lists
 
 Enter your choice: 2
 
 Total no. of members are
 : 4
 Do you want to continue :[y/n]y
 1.Insert by position
 2.Total no. of members in the list
 3.Delete by position
 4.Concatenation of two lists
 
 Enter your choice: 3
 
 Enter the position to delete: 4
 
 Original list is
 Head Node Details are :
 Total nodes is the list are 	 Head node address 	 First node address
 4				  0x17c9010		  0x17c9040
 Name of the member 	 PRN no. 	 Designation 	   Previous node address 	 Current node address 	 Next node address
 Yash			  15001		  President		  0x17c9010		  0x17c9040		  0x17c9070
 Tanmay			  15002		  Member		  0x17c9040		  0x17c9070		  0x17c90a0
 Rishi			  15003		  Member		  0x17c9070		  0x17c90a0		  0x17c90d0
 Shivam			  15004		  Secretary		  0x17c90a0		  0x17c90d0		  0
 
 List with deleted element is
 Head Node Details are :
 Total nodes is the list are 	 Head node address 	 First node address
 3				  0x17c9010		  0x17c9040
 Name of the member 	 PRN no. 	 Designation 	   Previous node address 	 Current node address 	 Next node address
 Yash			  15001		  President		  0x17c9010		  0x17c9040		  0x17c9070
 Tanmay			  15002		  Member		  0x17c9040		  0x17c9070		  0x17c90a0
 Rishi			  15003		  Secretary		  0x17c9070		  0x17c90a0		  0
 
 Do you want to continue :[y/n]y
 1.Insert by position
 2.Total no. of members in the list
 3.Delete by position
 4.Concatenation of two lists
 
 Enter your choice: 4
 
 Enter the details of the 2nd list
 
 Enter the name of the member : 4
 
 Enter the prn no of the member : 15004
 
 Do you want to add next element [y/n]
 n
 Head Node Details are :
 Total nodes is the list are 	 Head node address 	 First node address
 1				  0x17c9100		  0x17c9130
 Name of the member 	 PRN no. 	 Designation 	   Previous node address 	 Current node address 	 Next node address
 4			  15004		  President		  0x17c9100		  0x17c9130		  0
 
 
 Original list is
 Head Node Details are :
 Total nodes is the list are 	 Head node address 	 First node address
 3				  0x17c9010		  0x17c9040
 Name of the member 	 PRN no. 	 Designation 	   Previous node address 	 Current node address 	 Next node address
 Yash			  15001		  President		  0x17c9010		  0x17c9040		  0x17c9070
 Tanmay			  15002		  Member		  0x17c9040		  0x17c9070		  0x17c90a0
 Rishi			  15003		  Secretary		  0x17c9070		  0x17c90a0		  0
 
 
 Concatenated list is
 Head Node Details are :
 Total nodes is the list are 	 Head node address 	 First node address
 4				  0x17c9010		  0x17c9040
 Name of the member 	 PRN no. 	 Designation 	   Previous node address 	 Current node address 	 Next node address
 Yash			  15001		  President		  0x17c9010		  0x17c9040		  0x17c9070
 Tanmay			  15002		  Member		  0x17c9040		  0x17c9070		  0x17c90a0
 Rishi			  15003		  Member		  0x17c9070		  0x17c90a0		  0x17c9130
 4			  15004		  Secretary		  0x17c90a0		  0x17c9130		  0
 
 Do you want to continue :[y/n]n
 */


