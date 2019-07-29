#include<iostream>
#define max 100
using namespace std;

class Stack
{
	private:
		int stack[max],top;

	public:
		Stack()
		{
			top=-1;
		}
		int MaxArea(int [],int);
};

int isEmpty(int top)
{
	if(top==-1)
		return 1;
	else 
		return 0;
}

void push(int stack[],int *top,int num)
{
	stack[++(*top)]=num;
	return ;
}

int pop(int stack[],int *top)
{
	int n;
	if(*top==-1)
		return -1;
	n=stack[*top];
	(*top)--;
	return n;
}

int Stack::MaxArea(int arr[],int size)
{
	int i=0,area,max_area=-1,j;
	while(i<size)
	{
		if(isEmpty(top) || arr[stack[top]]<=arr[i])
			push(stack,&top,i++);

		else
		{
			j=pop(stack,&top);
			if(isEmpty(top))
				area=arr[j]*i;

			else
				area=arr[j]*(i-stack[top]-1);

			if(area>max_area)
				max_area=area;

		}
	}
	return max_area;
}

int main(void)
{
	int size,i;
	Stack ob;
	cout<<"enter the size"<<endl;
	cin>>size;
	int arr[size];
	cout<<"enter the values"<<endl;
	for(i=0;i<size;i++)
		cin>>arr[i];

	cout<<"max area is "<<ob.MaxArea(arr,size)<<endl;
}




