#include<iostream>
#include<cstring>
#define max 100
using namespace std;

class Stack
{
	private:
		int q1[max],q2[max];
		int f1,r1,f2,r2;

	public:

		Stack()
		{
			f1=-1;
			r1=-1;
			f2=-1;
			r2=-1;
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
	int v;
	if(r2==max)
		return ;

	if(r2==-1)
		f2=0;

	q2[++r2]=num;
	while(!isEmpty(f1,r1))
	{
		v=dequeue();
		q2[++r2]=v;
	}
	memcpy(q1,q2,sizeof(q2));
	f1=f2;
	r1=r2;
	f2=r2=-1;
}

int Stack::pop(void)
{
	if(f1==-1)
		return -1;

	return q1[f1++];
}

void Stack::display()
{
	int v;
	for(v=f1;v<=r1;v++)
		cout<<q1[v]<<" ";

	cout<<endl;
}

int Stack::dequeue(void)
{
	int num;
	num=q1[f1++];
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
