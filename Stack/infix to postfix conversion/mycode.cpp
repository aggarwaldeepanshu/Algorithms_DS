#include<iostream>
#include<string>
using namespace std;

class Stack
{
	public:
		void InfixtoPostfix(string);
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

char peek(char stack[],int top)
{
	return stack[top];
}

int precedence(char ch)
{
	if(ch=='+'||ch=='-')
		return 1;

	if(ch=='*'||ch=='/')
		return 2;

	if(ch=='^')
		return 3;
	else
		return -1;
}

void Stack::InfixtoPostfix(string str)
{
	int n,i=0,top=-1;
	n=str.length();
	char stack[n],ch;

	while(i<n)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
		{
			while(!isempty(top)&&precedence(str[i])<=precedence(peek(stack,top)))
			{
				ch=pop(stack,&top);
				cout<<ch;
			}
			push(stack,str[i],&top);
		}

		else if(str[i]=='(')
			push(stack,str[i],&top);

		else if(str[i]==')')
		{
			while(stack[top]!='(')
			{
				ch=pop(stack,&top);
				cout<<ch;
			}
			pop(stack,&top);
		}

		else
			cout<<str[i];

		i++;
	}
	while(!isempty(top))
	{
		ch=pop(stack,&top);
		cout<<ch;
	}
}

int main(void)
{
	Stack ob;

	string str;
	cout<<"enter the expression"<<endl;
	getline(cin,str);

	ob.InfixtoPostfix(str);
}
