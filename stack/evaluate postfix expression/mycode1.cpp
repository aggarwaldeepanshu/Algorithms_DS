#include<iostream>
#include<string>
using namespace std;

class Stack
{
	public:
		int PostfixEvaluation(string);
};

int isempty(int top)
{
	if(top==-1)
		return 1;
	else 
		return 0;
}

void push(int stack[],int n,int *top)
{
	stack[++(*top)]=n;
	return ;
}

int pop(int stack[],int *top)
{
	int n;
	if(*top==-1)
		return -1;
	n=stack[*top];
	(*top)--;
	return n;
}

int evaluate(int a,int b,char ch)
{
	switch(ch)
	{
		case '+':
			return a+b;
		case '-':
			return b-a;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '^':
			return a^b;
	}
}

int Stack::PostfixEvaluation(string str)
{
	int n,i=0,top=-1,a,b;
	n=str.length();
	int stack[n];

	while(i<n)
	{
		if(str[i]>='0' && str[i]<='9')

			push(stack,str[i]-'0',&top);

		else
		{
			a=pop(stack,&top);
			b=pop(stack,&top);
			a=evaluate(a,b,str[i]);
			push(stack,a,&top);
		}
		i++;
	}
	return stack[top];
}

int main(void)
{
	Stack ob;
	int n;
	string str;
	cout<<"enter the expression"<<endl;
	getline(cin,str);

	n=ob.PostfixEvaluation(str);
	cout<<n<<endl;
}
