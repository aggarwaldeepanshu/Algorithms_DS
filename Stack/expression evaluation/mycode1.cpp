#include<iostream>
#include<string>
using namespace std;

class Stack
{
	public:
		int ExpressionEvaluation(string);
};

int isEmpty(int top)
{
	if(top==-1)
		return 1;
	else 
		return 0;
}

void push1(char stack[],int *top,char ch)
{
	stack[++(*top)]=ch;
	return ;
}

void push2(int stack[],int *top,int n)
{
	stack[++(*top)]=n;
	return ;
}

char pop1(char stack[],int *top)
{
	char ch='\0';
	if(*top==-1)
		return ch;
	ch=stack[*top];
	(*top)--;
	return ch;
}

int pop2(int stack[],int *top)
{
	if(*top==-1)
		return -1;
	int n=stack[*top];
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
			return b/a;
	}
}

int precedence(char ch)
{
	if(ch=='*'||ch=='/')
		return 2;
	else if(ch=='+'||ch=='-')
		return 1;
	else
		return -1;
}

int Stack::ExpressionEvaluation(string str)
{
	int n,val,i=0,top1=-1,top2=-1,a,b;
	n=str.length();
	char s1[n],ch;
	int s2[n];
	while(i<n)
	{
		if(str[i]>='0' && str[i]<='9')
			push2(s2,&top2,str[i]-'0');

		else if(str[i]=='(')
			push1(s1,&top1,str[i]);

		else if(str[i]==')')
		{
			ch=pop1(s1,&top1);
			while(ch!='(')
			{
				a=pop2(s2,&top2);
				b=pop2(s2,&top2);
				val=evaluate(a,b,ch);
				push2(s2,&top2,val);
				ch=pop1(s1,&top1);
			}
		}

		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			if(!isEmpty(top1) && precedence(str[i])<precedence(s1[top1]))
			{
				while(precedence(str[i])<precedence(s1[top1]))
				{
					ch=pop1(s1,&top1);
					a=pop2(s2,&top2);
					b=pop2(s2,&top2);
					val=evaluate(a,b,ch);
					push2(s2,&top2,val);
				}
			}
			push1(s1,&top1,str[i]);
		}
		i++;
	}
	while(!isEmpty(top1))
	{
		ch=pop1(s1,&top1);
		a=pop2(s2,&top2);
		b=pop2(s2,&top2);
		val=evaluate(a,b,ch);
		push2(s2,&top2,val);
	}
	return s2[top2];
}

int main(void)
{
	int i,ans;
	Stack ob;
	string str;
	cout<<"enter the expression"<<endl;
	cin>>str;
	ans=ob.ExpressionEvaluation(str);
	cout<<ans<<endl;
}
