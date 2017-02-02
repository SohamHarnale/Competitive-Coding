/*
 * Name: Soham Harnale
 * Roll No: SE202061
 */


#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

const int iSize=10;

class cStack1
{
	int iTop;
	char cArr[iSize];

public:
	cStack1()
	{
		iTop=-1;
	}


	int isempty()
	{
		if(iTop==-1)
			return 1;
		else
			return 0;
	}

	int isfull()
	{
		if(iTop==iSize-1)
			return 1;
		else
			return 0;
	}

	void vPush(char a)
	{
		if(!isfull())
		{
			iTop++;
			cArr[iTop]=a;
		}
		else
			cout<<"Stack overflow !"<<endl;
	}

	char cPop()
	{
		char temp;
		if(!isempty())
		{
			temp=cArr[iTop];
			iTop--;
			return temp;
		}
		else
		{
			cout<<"Stack underflow !"<<endl;
			return ' ';
		}
	}

	friend class cConvert;
};


class cStack2
{
	char cAr[iSize][iSize];
	int iTop;

public:
	cStack2()
	{
		iTop=-1;
		for(int i=0;i<iSize;i++)
		{
			for(int j=0;j<iSize;j++)
			{
				cAr[i][j]='\0';
			}
		}
	}

	int isempty()
	{
		if(iTop==-1)
			return 1;
		else
			return 0;
	}


	int isfull()
	{
		if(iTop==iSize-1)
			return 1;
		else
			return 0;
	}

	void vPush(string &p)
	{
		if(!isfull())
		{
			iTop++;
			p.copy(cAr[iTop],iSize);
		}
		else
			cout<<"Stack overflow !"<<endl;
	}

	string vPop()
	{
		if(!isempty())
		{
			string temp;
			temp=cAr[iTop];
			iTop--;
			return temp;
		}
		else
		{
			cout<<"Stack underflow !"<<endl;
			return '\0';
		}
	}
	friend class cConvert;
};

class cConvert
{
	char exp[iSize];

public :
	void vGetdata()
	{
		cout<<"Enter expression in standard form : "<<endl;
		cin>>exp;
	}

	void vDisplay()
	{
		cout<<exp<<endl;
	}

	void vinfixPost(cConvert &);
	void vinfixPre(cConvert &);
	void vpostInfix(cConvert &);
	void vpreInfix(cConvert &);
	void vpostPre(cConvert &);
	void vprePost(cConvert &);
	int  iPrecedence(char);
	void vreverse();
};

int cConvert::iPrecedence(char c)
{
	if(c=='^')
		return 4;
	else if(c=='*' || c=='/')
		return 3;
	else if(c=='+' || c=='-')
		return 2;
	else if(c=='(')
		return 1;
	else
		return 0;
}

void cConvert::vinfixPost(cConvert &ex)
{
	cStack1 s1;
	int k=0,i=0;
	char tkn;

	tkn=ex.exp[i];

	while(tkn!='\0')
	{
		if(((tkn>='a') && (tkn<='z')) || ((tkn>='A') && (tkn<='Z')))
		{
			exp[k]=ex.exp[i];
			k++;
		}
		else
		{
			if(tkn == '(')
			{
				s1.vPush('(');
			}
			else
			{
				if(tkn==')')
				{
					while((tkn=s1.cPop())!='(')
					{
						exp[k]=tkn;
						k++;
					}
				}
				else
				{
					while((!s1.isempty()) && (iPrecedence(s1.cArr[s1.iTop]))>=iPrecedence(tkn))
					{
						exp[k]=s1.cPop();
						k++;
					}
					s1.vPush(tkn);
				}
			}
		}
		i++;
		tkn=ex.exp[i];
	}
	while(!s1.isempty())
	{
		exp[k]=s1.cPop();
		k++;
	}
	exp[k]='\0';
}

void cConvert::vinfixPre(cConvert &ex)
{
	cStack1 s1;
	int k=0,i=0;
	char tkn;

	ex.vreverse();
	tkn=ex.exp[i];

	while(tkn!='\0')
	{
		if(((tkn>='a') && (tkn<='z')) || ((tkn>='A') && (tkn<='Z')))
				{
					exp[k]=ex.exp[i];
					k++;
				}
				else
				{
					if(tkn == ')')
					{
						s1.vPush(')');
					}
					else
					{
						if(tkn=='(')
						{
							while((tkn=s1.cPop())!=')')
							{
								exp[k]=tkn;
								k++;
							}
						}
						else
						{
							while((!s1.isempty()) && (iPrecedence(s1.cArr[s1.iTop]))>=iPrecedence(tkn))
							{
								exp[k]=s1.cPop();
								k++;
							}
							s1.vPush(tkn);
						}
					}
				}
				i++;
				tkn=ex.exp[i];
			}
			while(!s1.isempty())
			{
				exp[k]=s1.cPop();
				k++;
			}
			exp[k]='\0';
vreverse();
}


void cConvert::vpostInfix(cConvert &ex)
{
	cStack2 s;
	int i=0;
	string s1,s2,s3;
	char tkn=ex.exp[i];

	while(tkn!='\0')
	{
		if(((tkn>='a') && (tkn<='z')) || ((tkn >='A') && (tkn<='Z')))
		{
			s1=tkn;
			s.vPush(s1);
		}
		else
		{
			if(s.iTop<1)
				cout<<"Error-Input values are not sufficient"<<endl;
			else
			{
				s1=s.vPop();
				s2=s.vPop();
				s3="("+s2+tkn+s1+")";
				s.vPush(s3);
			}
		}
		tkn=ex.exp[++i];
		strcpy(exp,s.cAr[s.iTop]);
	}
}

void cConvert::vpreInfix(cConvert &ex)
{
	ex.vreverse();
	cStack2 s;
	int i=0;
	string s1,s2,s3;
	char tkn=ex.exp[i];

	while(tkn!='\0')
	{
		if(((tkn>='a') && (tkn<='z')) || ((tkn>='A') && (tkn<='Z')))
		{
			s1=tkn;
			s.vPush(s1);
		}
		else
		{
			if(s.iTop<1)
				cout<<"Error-Input insufficient"<<endl;
			else
			{
				s1=s.vPop();
				s2=s.vPop();
				s3="("+s1+tkn+s2+")";
				s.vPush(s3);
			}
		}
		tkn=ex.exp[++i];
		strcpy(exp,s.cAr[s.iTop]);
	}
}

void cConvert::vpostPre(cConvert &ex)
{
	cStack2 s;
	int i=0;
	string s1,s2,s3;
	char tkn;
	tkn=ex.exp[i];

	while(tkn!='\0')
	{
		if(((tkn>='a') && (tkn<='z')) || ((tkn>='A') && (tkn<='Z')))
		{
			s1=tkn;
			s.vPush(s1);
		}
		else
		{
			if(s.iTop<1)
				cout<<"Error-Input insufficient"<<endl;
			else
			{
				s1=s.vPop();
				s2=s.vPop();
				s3=tkn+s2+s1;
				s.vPush(s3);
			}
		}
		tkn=ex.exp[++i];
		strcpy(exp,s.cAr[s.iTop]);
	}

	while(!s.isempty() && s.iTop>0)
	{
		s1=s.vPop();
		s2=s.vPop();
		s3=s2+s1;
		s.vPush(s3);
		tkn=ex.exp[++i];
		strcpy(exp,s.cAr[s.iTop]);
	}
}

void cConvert::vprePost(cConvert &ex)
{
	ex.vreverse();
	cStack2 s;
	int i=0;
	string s1,s2,s3;
	char tkn=ex.exp[i];

	while(tkn!='\0')
	{
		if(((tkn>='a') && (tkn<='z')) || ((tkn>='A') && (tkn<='Z')))
		{
			s1=tkn;
			s.vPush(s1);
		}
		else
		{
			if(s.iTop<1)
				cout<<"Input values insufficient"<<endl;
			else
			{
				s1=s.vPop();
				s2=s.vPop();
				s3=s1+s2+tkn;
				s.vPush(s3);
			}
		}
		tkn=ex.exp[++i];
		strcpy(exp,s.cAr[s.iTop]);
	}
	tkn=ex.exp[i];
	while(tkn!='\0')
	{
		s1=s.vPop();
		s3=s3+tkn;
		s.vPush(s3);
		i++;
		tkn=ex.exp[i];
		strcpy(exp,s.cAr[s.iTop]);
	}
}

void cConvert::vreverse()
{
	cStack1 s1;
	int i=0;

	while(exp[i]!='\0')
	{
		s1.vPush(exp[i]);
		i++;
	}
	i=0;
	do
	{
		exp[i]=s1.cPop();
		i++;
	}while(!s1.isempty());
	exp[i]='\0';
}

int main()
{
	cConvert a,b;
	char ans;
	int choice;
	do
	{
		cout<<"Select the stack conversion : "<<endl;
		cout<<"1.Infix to Postfix"<<endl;
		cout<<"2.Infix to Prefix"<<endl;
		cout<<"3.Postfix to Infix"<<endl;
		cout<<"4.Prefix to Infix"<<endl;
		cout<<"5.Postfix to Prefix"<<endl;
		cout<<"6.Prefix to Postfix"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1 :a.vGetdata();
					b.vinfixPost(a);
					cout<<"Conversion from infix to postfix : "<<endl;
					b.vDisplay();
					break;
			case 2 :a.vGetdata();
					b.vinfixPre(a);
					cout<<"Conversion from infix to prefix : "<<endl;
					b.vDisplay();
					break;
			case 3 :a.vGetdata();
					b.vpostInfix(a);
					cout<<"Conversion from postfix to infix : "<<endl;
					b.vDisplay();
					break;
			case 4 :a.vGetdata();
					b.vpreInfix(a);
					cout<<"Conversion from prefix to infix : "<<endl;
					b.vDisplay();
					break;
			case 5 :a.vGetdata();
					b.vpostPre(a);
					cout<<"Conversion from postfix to prefix : "<<endl;
					b.vDisplay();
					break;
			case 6 :a.vGetdata();
					b.vprePost(a);
					cout<<"Conversion from prefix to postfix : "<<endl;
					b.vDisplay();
					break;
			default:cout<<"Wrong choice ! "<<endl;
					break;
			}
			cout<<"Do you want to continue ?(y/n)"<<endl;
			cin>>ans;
		}while(ans=='y');
	return 0;
}





