#include<iostream>
#define max 100
using namespace std;

class Stack
{
	private:
		int arr[max];
		int top1,top2;

	public:

		Stack()
		{
			top1=-1;
			top2=max;
		}

		void push1(int);
		void push2(int);
		int pop1(void);
		int pop2(void);
};

void Stack::push1(int num)
{
	if(top2==top1+1)
	{
		cout<<"overflow"<<endl;
		return;
	}
	arr[++top1]=num;
}

void Stack::push2(int num)
{
	if(top2==top1+1)
	{
		cout<<"overflow"<<endl;
		return ;
	}
	arr[--top2]=num;
}

int Stack::pop1(void)
{
	int num;
	if(top1==-1)
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	num=arr[top1--];
	return num;
}

int Stack::pop2(void)
{
	int num;
	if(top2==max)
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	num=arr[top2++];
	return num;
}

int main(void)
{
	Stack ob;
	ob.push1(10);
	ob.push1(14);
	ob.push1(2);
	ob.push2(18);
	ob.push2(20);
	ob.push2(6);
	ob.push1(100);
	cout<<"element in stack1 is "<<ob.pop1()<<endl;
	cout<<"element in stack2 is "<<ob.pop2()<<endl;
}
