#include<iostream>
#include<string>
using namespace std;

class Stack
{
	public:
		int BracketReversal(string);
};

int isempty(int top)
{
	if(top==-1)
		return 1;
	else 
		return 0;
}

void push(char stack[],char ch,int *top)
{
	stack[++(*top)]=ch;
	return ;
}

char pop(char stack[],int *top)
{
	char ch='\0';
	if(*top==-1)
		return ch;
	ch=stack[*top];
	(*top)--;
	return ch;
}

int Stack::BracketReversal(string str)
{
	int n,i=0,top=-1,k=1,count=0;
	n=str.length();
	char stack[n],ch;
	char a,b;

	while(i<n-1 && i+k<n)
	{
		if(str[i]=='{' && str[i+k]=='}')
		{
			if(i==0)
				i=2;
			else
			{
				i--;
				k+=2;
			}

			top--;
		}
		else
		{
			push(stack,str[i],&top);
			i+=k;
			k=1;
		}
	}

	if(i==n-1 || i+k>=n)
		push(stack,str[i],&top);

	while(!isempty(top))
	{
		a=pop(stack,&top);
		b=pop(stack,&top);

		if((a=='\0' && b!='\0')||(a!='\0' && b=='\0'))
			return -1;

		if(b=='}' && a=='{')
			count+=2;

		else if((b=='{' && a=='{')||(b=='}' && a=='}'))
			count++;
	}
	return count;
}

int main(void)
{
	Stack ob;
	int count;
	string str;
	cout<<"enter the expression"<<endl;
	getline(cin,str);

	count=ob.BracketReversal(str);
	if(count==-1)
		cout<<"cannot be balanced"<<endl;
	else
		cout<<"bracket reversals needed is "<<count<<endl;
}
