#include<iostream>
#define max 100
using namespace std;

class Stack
{
	private:
		int arr[max],aux[max];
		int top,top1;

	public:

		Stack()
		{
			top=-1;
			top1=-1;
		}

		void push(int);
		int pop(void);
		int getMin(void);
};

int isFull(int top)
{
	if(top==max-1)
		return 1;
	else
		return 0;
}

int isEmpty(int top)
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int Stack::getMin(void)
{
	return aux[top1];
}

void Stack::push(int num)
{
	if(isFull(top))
	{
		cout<<"overflow"<<endl;
		return;
	}

	if(top1==-1)
		aux[++top1]=num;

	if(aux[top1]>num)
	{
		aux[++top1]=num;
	}

	arr[++top]=num;
}

int Stack::pop(void)
{
	int num;
	if(isEmpty(top))
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	num=arr[top--];

	if(aux[top1]==num)
		top1--;

	return num;
}

int main(void)
{
	Stack ob;
	int num;
	cout<<"enter -1 to exit"<<endl;
	cin>>num;
	while(num!=-1)
	{
		ob.push(num);
		cin>>num;
	}
	cout<<"minimum value is "<<ob.getMin()<<endl;
        cout<<"element removed is "<<ob.pop()<<endl;
        cout<<"element removed is "<<ob.pop()<<endl;
	cout<<"minimum value is "<<ob.getMin()<<endl;
}
