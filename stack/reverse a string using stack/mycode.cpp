#include<iostream>
#include<string>
using namespace std;

class Stack
{
	public:
		string ReverseString(string);
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

string Stack::ReverseString(string str)
{
	int n,i=0,top=-1;
	n=str.length();
	char stack[n],ch;

	while(i<n)
	{
		push(stack,str[i],&top);
		i++;
	}
	i=0;
	while(!isempty(top))
	{
		str[i]=pop(stack,&top);
		i++;
	}
	return str;
}

int main(void)
{
	Stack ob;

	string str;
	cout<<"enter the expression"<<endl;
	getline(cin,str);

	str=ob.ReverseString(str);
	cout<<"reversed string is "<<str<<endl;
}
