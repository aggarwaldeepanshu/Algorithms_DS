#include<iostream>
#define max 100
using namespace std;

class queue
{
	private:
		int s1[max],s2[max],top1,top2;

	public:
		queue()
		{
			top1=-1;
			top2=-1;
		}
		void enqueue(int);
		int dequeue(void);
};

int isEmpty(int top)
{
	return (top==-1);
}

int pop(int stack[],int *top)
{
	return stack[(*top)--];
}

void push(int stack[],int *top,int num)
{
	stack[++(*top)]=num;
	return ;
}

void queue::enqueue(int num)
{
	push(s1,&top1,num);
	return ;
}

int queue::dequeue(void)
{
	int val;

	if(isEmpty(top2))
	{
		while(!isEmpty(top1))
		{
			val=pop(s1,&top1);
			push(s2,&top2,val);
		}
	}
	val=pop(s2,&top2);

	return val;
}

int main(void)
{
	int num;
	queue ob;
	cout<<"enter -1 to exit"<<endl;
	cin>>num;
	while(num!=-1)
	{
		ob.enqueue(num);
		cin>>num;
	}
	cout<<"element at top is "<<ob.dequeue()<<endl;
	cout<<"element at top is "<<ob.dequeue()<<endl;
	cout<<"element at top is "<<ob.dequeue()<<endl;
}
