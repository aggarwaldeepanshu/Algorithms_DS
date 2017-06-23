#include<iostream>
using namespace std;

int available=0;

class Queue
{
	private:
		int *arr,*front,*rear,*nextIndex;
		int size,qn;

	public:
		Queue(int n,int number)
		{
			int i;
			size=n;
			qn=number;
			arr=new int [size];
			front=new int [qn];
			rear=new int [qn];
			nextIndex=new int [size];

			for(i=0;i<size;i++)
			{
				nextIndex[i]=i+1;
			}
			nextIndex[size-1]=-1;

			for(i=0;i<qn;i++)
			{
				front[i]=-1;
				rear[i]=-1;
			}

		}

		void enqueue(int,int);
		int dequeue(int);
};

int isFull()
{
	if(available==-1)
		return 1;
	else
		return 0;
}

int isEmpty(int front[],int qn)
{
	if(front[qn]==-1)
		return 1;
	else
		return 0;
}

void Queue::enqueue(int queue_number,int key)
{
	int i;
	if(isFull())
	{
		cout<<"overflow"<<endl;
		return ;
	}

	i=available;
	available=nextIndex[i];

	if(isEmpty(front,queue_number))
		front[queue_number]=i;
	else
		nextIndex[rear[queue_number]]=i;

	nextIndex[i]=-1;

	rear[queue_number]=i;

	arr[i]=key;

	return ;
}

int Queue::dequeue(int queue_number)
{
	int i;
	if(isEmpty(front,queue_number))
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	i=front[queue_number];
	front[queue_number]=nextIndex[i];
	nextIndex[i]=available;
	available=i;

	return arr[i];
}

int main(void)
{
	int size,qn,s,k;
	cout<<"enter size and number of Queues"<<endl;
	cin>>size>>qn;

	Queue ob(size,qn);

	cout<<"enter Queue number and data to push"<<endl;
	cout<<"enter -1 -1 to exit"<<endl;
	cin>>s>>k;
	while(s!=-1 && k!=-1)
	{
		ob.enqueue(s,k);
		cin>>s>>k;
	}

	cout<<"element removed from Queue 0 is "<<ob.dequeue(0)<<endl;
	cout<<"element removed from Queue 1 is "<<ob.dequeue(1)<<endl;
	cout<<"element removed from Queue 2 is "<<ob.dequeue(2)<<endl;
	cout<<"element removed from Queue 1 is "<<ob.dequeue(1)<<endl;
}

