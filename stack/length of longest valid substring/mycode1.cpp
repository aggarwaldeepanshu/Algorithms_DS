#include<iostream>
#include<string>
using namespace std;

class Stack
{
	public:
		int LongestSubstring(string);
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

int Stack::LongestSubstring(string str)
{
	int n,i=0,top=-1,count=0;
	n=str.length();
	char stack[n],ch;

	while(i<n)
	{
		if(str[i]=='(')
		{
			push(stack,str[i],&top);
			i++;
		}

		else if(str[i]==')')
		{
			ch=pop(stack,&top);
			if(str[i]==')' && ch=='(')
				count+=2;

			i++;
		}
	}
	return count;
}

int main(void)
{
	int count;
	Stack ob;

	string str;
	cout<<"enter the expression"<<endl;
	getline(cin,str);
	count=ob.LongestSubstring(str);
	cout<<"length is "<<count<<endl;
}
