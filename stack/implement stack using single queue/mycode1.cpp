#include<iostream>
#define max 100
using namespace std;

class Stack
{
	private:
		int q[max];
		int front,rear;

	public:

		Stack()
		{
			front=-1;
			rear=-1;
		}
		void display(void);
		int dequeue(void);
		void push(int);
		int pop(void);
};

int isEmpty(int front,int rear)
{
	if(front==-1||front==rear+1)
		return 1;
	else
		return 0;
}

void Stack::push(int num)
{
	int v,size;
	if(rear==max)
		return ;

	if(rear==-1)
	{
		size=0;
		front=0;
	}

	else if(rear!=-1)
		size=rear-front+1;

	q[++rear]=num;
	while(size>0)
	{
		v=dequeue();
		q[++rear]=v;
		size--;
	}

}

int Stack::pop(void)
{
	if(front==-1)
		return -1;

	return q[front++];
}

void Stack::display()
{
	int v;
	for(v=front;v<=rear;v++)
		cout<<q[v]<<" ";

	cout<<endl;
}

int Stack::dequeue(void)
{
	int num;
	num=q[front++];
	return num;
}

int main(void)
{
	Stack ob;
	int num,v;
	cout<<"enter -1 to exit"<<endl;
	cin>>num;
	while(num!=-1)
	{
		ob.push(num);
		cin>>num;
	}
	cout<<"before removing"<<endl;
	ob.display();
	v=ob.pop();
	if(v==-1)
		cout<<"empty stack"<<endl;
	else
		cout<<"removed value is "<<v<<endl;

	cout<<"after removing"<<endl;
	ob.display();
}
