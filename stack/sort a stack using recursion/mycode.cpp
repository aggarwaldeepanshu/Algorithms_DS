#include<iostream>
#define max 100
using namespace std;

class Stack
{
	public:
		void SortStack(int [],int);
};

int isempty(int top)
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void push(int stack[],int top,int num)
{
	int temp;
	if(top==0)
	{
		stack[top]=num;
		return ;
	}
	int n=top;
	while(top>0 && stack[top-1]>num)
	{
		temp=stack[top-1];
		stack[top-1]=num;
		stack[top]=temp;
		top--;
	}
	return ;
}

int pop(int stack[],int top)
{
	if(top==-1)
		return -1;

	return stack[top];
}

void Stack::SortStack(int stack[],int top)
{
	int num;
	if(isempty(top))
		return ;

	num=pop(stack,top);
	SortStack(stack,top-1);
	push(stack,top,num);
	return;
}

int main(void)
{
	Stack ob;
	int i=-1,j,num;
	int stack[max];

	cout<<"enter -1 to exit"<<endl;
	cin>>num;
	while(num!=-1)
	{
		stack[++i]=num;
		cin>>num;
	}
	ob.SortStack(stack,i);
	cout<<"after sorting"<<endl;
	for(j=0;j<=i;j++)
		cout<<stack[j]<<" ";
}
