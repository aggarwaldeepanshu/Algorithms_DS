#include<iostream>
#define max 100
using namespace std;

class dequeue
{
	private:
		int *arr;
		int front,rear,size;

	public:

		dequeue(int n)
		{
			size=n;
			arr=new int[size];
			rear=0;
			front=-1;
		}
		void InsertFront(int);
		void InsertRear(int);
		int DeleteFront(void);
		int DeleteRear(void);
		int getFront(void);
		int getRear(void);
};

int isFull(int front,int rear,int size)
{
	if((front==0 && rear==size-1)|| (front== (rear+1)%size ) )
		return 1;
	else
		return 0;
}

int isEmpty(int front)
{
	if(front==-1)
		return 1;
	else
		return 0;
}

int dequeue::getFront(void)
{
	if(isEmpty(front))
		return -1;
	else
		return arr[front];
}

int dequeue::getRear(void)
{
	if(isEmpty(front))
		return -1;
	else
		return arr[rear];
}

void dequeue::InsertFront(int num)
{
	if(isFull(front,rear,size))
	{
		cout<<"overflow"<<endl;
		return ;
	}

	if(front==0)
		front=size-1;

	else if(front==-1)
		front=0;

	else
		front--;

	arr[front]=num;

	return ;
}

void dequeue::InsertRear(int num)
{
	if(isFull(front,rear,size))
	{
		cout<<"overflow"<<endl;
		return ;
	}

	if(rear==size-1)
		rear=0;

	else if(front==-1)
		front=0;

	else
		rear++;

	arr[rear]=num;

	return ;
}

int dequeue::DeleteFront(void)
{
	if(isEmpty(front))
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	int temp;

	if(front==rear)
	{
		temp=arr[front];
		front=-1;
		rear=0;
	}

	else
	{
		temp=arr[front];
		front++;
	}

	return temp;
}

int dequeue::DeleteRear(void)
{
	if(isEmpty(front))
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	int temp;

	if(front==rear)
	{
		temp=arr[front];
		front=-1;
		rear=0;
	}

	else
	{
		temp=arr[rear];
		rear--;
	}

	return temp;
}

int main(void)
{
	int num,n;
	cout<<"enter the size"<<endl;
	cin>>n;
	dequeue ob(n);

	cout<<"enter -1 to exit"<<endl;
	cout<<"enter at front end"<<endl;
	cin>>num;
	while(num!=-1)
	{
		ob.InsertFront(num);
		cin>>num;
	}

	cout<<"enter at rear end"<<endl;
	cin>>num;
	while(num!=-1)
	{
		ob.InsertRear(num);
		cin>>num;
	}

	cout<<"element at rear end is "<<ob.getRear()<<endl;
	cout<<"element removed from rear end is "<<ob.DeleteRear()<<endl;
	cout<<"after removing, element at rear end is "<<ob.getRear()<<endl;

	cout<<"element at front end is "<<ob.getFront()<<endl;
	cout<<"element removed from front end is "<<ob.DeleteFront()<<endl;
	cout<<"after removing, element at front end is "<<ob.getFront()<<endl;

}
