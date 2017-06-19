#include<iostream>
#include<string>
using namespace std;

class Stack
{
	public:
		int BalancedExpression(string);
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

int Stack::BalancedExpression(string str)
{
	int n,i=0,top=-1;
	n=str.length();
	char stack[n],ch;

	while(i<n)
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')
		{
			push(stack,str[i],&top);
			i++;
		}

		else if(str[i]==')'||str[i]==']'||str[i]=='}')
		{
			ch=pop(stack,&top);
			if(str[i]==')' && ch=='(')
				i++;

			else if(str[i]=='}' && ch=='{')
				i++;

			else if(str[i]==']' && ch=='[')
				i++;

			else
				return 0;
		}
	}

	if(isempty(top))
		return 1;
	else
		return 0;
}

int main(void)
{
	Stack ob;

	string str;
	cout<<"enter the expression"<<endl;
	getline(cin,str);

	if(ob.BalancedExpression(str))
		cout<<"balanced"<<endl;
	else
		cout<<"not balanced"<<endl;
}
