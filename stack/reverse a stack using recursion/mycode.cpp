#include<iostream>
#define max 100
using namespace std;

class Stack
{
	public:
		void reverse(int [],int);
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
	if(top==max-1)
		return ;

	stack[++top]=num;
}

int pop(int stack[],int top)
{
	if(top==-1)
		return -1;

	return stack[top];
}

void Stack::reverse(int stack[],int top)
{
	int num;
	static int i=-2;
	if(isempty(top))
		return ;

	num=pop(stack,top);
	i++;
	reverse(stack,top-1);
	push(stack,i,num);
i--;
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
	ob.reverse(stack,i);
	cout<<"stack in reverse order is"<<endl;
	for(j=0;j<=i;j++)
		cout<<stack[j]<<" ";
}
