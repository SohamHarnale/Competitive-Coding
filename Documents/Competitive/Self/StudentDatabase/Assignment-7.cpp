/*
 * Name: Soham Harnale
 * Roll No: SE202061
 */


#include<iostream>
using namespace std;
class cNode
{
    int iData;
    cNode *next;
    friend class CLL;
};
class CLL
{
    cNode *head;
    public:
    CLL()
    {
        head=new cNode;
        head->iData=0;
        head->next=head;
    }
    void vCreate()
    {
        cNode *temp,*curr;
        int ans;
        temp=head;
        do
        {
           curr=new cNode;
            cout<<"\nEnter a number.\t";
            cin>>curr->iData;
            curr->next=head;
            temp->next=curr;
            temp=curr;
            cout<<"\nEnter 1 to continue.\t";
            cin>>ans;
        }while(ans==1);
    }
    void vInsert()
    {
        cNode *temp,*curr;
        int pos,i=1,l=vLength();
        temp=head;
        if(head->next==head)
            cout<<"\nCurrent list is empty.\t";
        cout<<"\nEnter the position at which the number is to be entered.\t";
        cin>>pos;
        if(pos<=0||pos>(l+1))
            cout<<"\nInvalid position.\t";
        else
        {
           curr=new cNode;
            cout<<"\nEnter a number.\t";
            cin>>curr->iData;
            while(i<pos)
            {
                temp=temp->next;
                i++;
            }
          curr->next=temp->next;
            temp->next=curr;
       }
    }
    void vDelete()
    {
        cNode *temp,*NEXT;
        temp=head;
        if(temp->next!=head)
        {
            NEXT=temp->next;
            while(NEXT!=head)
            {
                if(NEXT->iData<0)
                {
                    temp->next=NEXT->next;
                    //temp=temp->next;
                    NEXT->next=NULL;
                    delete (NEXT);
                    NEXT=temp->next;
                }
                else
                {
                    temp=NEXT;
                    NEXT=NEXT->next;
                }
            }
        }
        else
            cout<<"\nNo data can be deleted since list is empty:";
    }
    int vLength()
    {
        cNode *temp;
        temp=head;
        int iLen=0;
        while(temp->next!=head)
        {
            temp=temp->next;
            iLen++;
        }
        return iLen;
    }
    CLL vSeparate(CLL P)
    {
        CLL N;
        cNode *temp,*temp_n,*temp_p,*copy;
        temp=head;
        temp_n=N.head;
        temp_p=P.head;
        if(temp->next==head)
            cout<<"\nOriginal list is empty\t";
        else
        {
            while(temp->next!=head)
            {
                temp=temp->next;
                if(temp->iData>=0)
                {
                    copy=new cNode;
                    copy->iData=temp->iData;
                    copy->next=P.head;
                    temp_p->next=copy;
                    temp_p=temp_p->next;

                }
                else
                {
                    copy=new cNode;
                    copy->iData=temp->iData;
                    copy->next=N.head;
                    temp_n->next=copy;
                    temp_n=temp_n->next;
                }
            }
        }
        return N;
    }
    CLL vSort()
    {
        CLL L;
        cNode *temp1,*temp,*curr;
        int t,l=vLength(),i=1;
        if(head->next==head)
            cout<<"\nList cannot be sorted since:";
        else
        {
            while(i<l)
            {
                temp1=head->next;
                while(temp1->next!=head)
                {
                    if(temp1->iData>temp1->next->iData)
                    {
                        t=temp1->iData;
                        temp1->iData=temp1->next->iData;
                        temp1->next->iData=t;
                    }
                    temp1=temp1->next;
                }
                i++;
            }
            temp=L.head;
            temp1=head->next;
            while(temp1!=head)
            {
                curr=new cNode;
                curr->iData=temp1->iData;
                temp->next=curr;
                curr->next=L.head;
                temp=curr;
                temp1=temp1->next;
            }
            cout<<"\nThe sorted list is:";
        }
        return L;
    }
    void vDisplay()
    {
        cNode *temp;
        temp=head;
        if(temp->next==head)
            cout<<"\nThe list is empty.\t";
        else
        {
            cout<<"\nHead Address\t\tHead Data\t\tNext Node Address\t";
            cout<<"\n"<<temp<<"\t\t"<<temp->iData<<"\t\t\t"<<temp->next;
            cout<<"\nCurrent Address\t\tData\t\t\tNext Node Address\t";
            while(temp->next!=head)
            {
                temp=temp->next;
                cout<<"\n"<<temp<<"\t\t"<<temp->iData<<"\t\t\t"<<temp->next;
            }
        }
    }
};

int main()
{
    CLL L1,Pos,Neg,M;
    int ch;
    do
    {
        cout<<"\nMENU\n1.Create a list.\n2.Insert numbers in the list.\n3.Display separate lists of positive and negative numbers.\n4.Merge the positive & negative lists.\n5.Delete list of negative integers from main list.\nEnter your choice.\t";
        cin>>ch;
        switch(ch)
        {
            case 1:
                L1.vCreate();
                L1.vDisplay();
                break;
            case 2:
                L1.vInsert();
                L1.vDisplay();
                break;
            case 3:
                Neg=L1.vSeparate(Pos);
                cout<<"\nList of positive numbers is:\t";
                Pos.vDisplay();
                cout<<"\nList of negative numbers is:\t";
                Neg.vDisplay();
                break;
            case 4:
            	M=L1.vSort();
            	M.vDisplay();
               	break;
            case 5:
            	L1.vDelete();
            	L1.vDisplay();
            	break;

            default:
                cout<<"\nInvalid choice.\t";
                break;
        }
        cout<<"\nEnter 1 if you want to continue.\t";
        cin>>ch;
    }while(ch==1);
    return 0;
}

/* OUTPUT 
 
 
 MENU
 1.Create a list.
 2.Insert numbers in the list.
 3.Display separate lists of positive and negative numbers.
 4.Merge the positive & negative lists.
 5.Delete list of negative integers from main list.
 Enter your choice.	1
 
 Enter a number.	2
 
 Enter 1 to continue.	1
 
 Enter a number.	5
 
 Enter 1 to continue.	1
 
 Enter a number.	2
 
 Enter 1 to continue.	0
 
 Head Address		Head Data		Next Node Address
 0x100200540		0			0x100300000
 Current Address		Data			Next Node Address
 0x100300000		2			0x100400000
 0x100400000		5			0x100202210
 0x100202210		2			0x100200540
 Enter 1 if you want to continue.	1
 
 MENU
 1.Create a list.
 2.Insert numbers in the list.
 3.Display separate lists of positive and negative numbers.
 4.Merge the positive & negative lists.
 5.Delete list of negative integers from main list.
 Enter your choice.	2
 
 Enter the position at which the number is to be entered.	2
 
 Enter a number.	8
 
 Head Address		Head Data		Next Node Address
 0x100200540		0			0x100300000
 Current Address		Data			Next Node Address
 0x100300000		2			0x100400010
 0x100400010		8			0x100400000
 0x100400000		5			0x100202210
 0x100202210		2			0x100200540
 Enter 1 if you want to continue.	1
 
 MENU
 1.Create a list.
 2.Insert numbers in the list.
 3.Display separate lists of positive and negative numbers.
 4.Merge the positive & negative lists.
 5.Delete list of negative integers from main list.
 Enter your choice.	3
 
 List of positive numbers is:
 Head Address		Head Data		Next Node Address
 0x100200550		0			0x100300020
 Current Address		Data			Next Node Address
 0x100300020		2			0x100300030
 0x100300030		8			0x100300040
 0x100300040		5			0x100300050
 0x100300050		2			0x100200550
 List of negative numbers is:
 The list is empty.
 Enter 1 if you want to continue.	1
 
 MENU
 1.Create a list.
 2.Insert numbers in the list.
 3.Display separate lists of positive and negative numbers.
 4.Merge the positive & negative lists.
 5.Delete list of negative integers from main list.
 Enter your choice.	4
 
 The sorted list is:
 Head Address		Head Data		Next Node Address
 0x100400020		0			0x100400030
 Current Address		Data			Next Node Address
 0x100400030		2			0x100400040
 0x100400040		2			0x100400050
 0x100400050		5			0x100400060
 0x100400060		8			0x100400020
 Enter 1 if you want to continue.	y
 Program ended with exit code: 0
 
 */
