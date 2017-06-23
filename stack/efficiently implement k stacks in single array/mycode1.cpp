#include<iostream>
#define max 100
using namespace std;

int available=0;

class stack
{
	private:
		int *arr,*top,*nextIndex;
		int size,sn;

	public:
		stack(int n,int number)
		{
			int i;
			size=n;
			sn=number;
			arr=new int [size];
			top=new int [sn];
			nextIndex=new int [size];

			for(i=0;i<size;i++)
			{
				nextIndex[i]=i+1;
			}
                        nextIndex[size-1]=-1;

			for(i=0;i<sn;i++)
				top[i]=-1;

		}

		void push(int,int);
		int pop(int);
};

int isFull()
{
	if(available==-1)
		return 1;
	else
		return 0;
}

int isEmpty(int top[],int sn)
{
	if(top[sn]==-1)
		return 1;
	else
		return 0;
}

void stack::push(int stack_number,int key)
{
	int i;
	if(isFull())
	{
		cout<<"overflow"<<endl;
		return ;
	}

	i=available;
	available=nextIndex[i];
	nextIndex[i]=top[stack_number];
	top[stack_number]=i;

	arr[i]=key;

	return ;
}

int stack::pop(int stack_number)
{
	int i;
	if(isEmpty(top,stack_number))
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	i=top[stack_number];
	top[stack_number]=nextIndex[i];
	nextIndex[i]=available;
	available=i;

	return arr[i];
}

int main(void)
{
	int size,sn,s,k;
	cout<<"enter size and number of stacks"<<endl;
	cin>>size>>sn;

	stack ob(size,sn);

	cout<<"enter stack number and data to push"<<endl;
	cout<<"enter -1 -1 to exit"<<endl;
	cin>>s>>k;
	while(s!=-1 && k!=-1)
	{
		ob.push(s,k);
		cin>>s>>k;
	}

	cout<<"element removed from stack 0 is "<<ob.pop(0)<<endl;
	cout<<"element removed from stack 1 is "<<ob.pop(1)<<endl;
	cout<<"element removed from stack 2 is "<<ob.pop(2)<<endl;
}

