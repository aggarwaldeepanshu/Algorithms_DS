#include<iostream>
using namespace std;

class Stack
{
	public:
		void MaximumofMinimum(int [],int,int []);
};

int isEmpty(int top)
{
	if(top==-1)
		return 1;
	else 
		return 0;
}

void push(int arr[],int *top,int num)
{
	arr[++(*top)]=num;
	return ;
}

int pop(int stack[],int *top)
{
	return stack[(*top)--];
}

void PrevSmaller(int arr[],int prev[],int size)
{
	int stack[size],top=-1,i=size-2,idx;
	push(stack,&top,size-1);

	while(i>=0)
	{
		if(!isEmpty(top))
		{
			idx=pop(stack,&top);

			while(arr[idx]>arr[i])
			{
				prev[idx]=i;
				if(isEmpty(top))
					break;

				idx=pop(stack,&top);
			}
			if(arr[idx]<=arr[i])
				push(stack,&top,idx);

		}
		push(stack,&top,i);
		i--;
	}
	while(!isEmpty(top))
	{
		idx=pop(stack,&top);
		prev[idx]=-1;
	}
}

void NextSmaller(int arr[],int next[],int size)
{
	int stack[size],top=-1,i=1,idx;
	push(stack,&top,0);

	while(i<size)
	{
		if(!isEmpty(top))
		{
			idx=pop(stack,&top);

			while(arr[idx]>arr[i])
			{
				next[idx]=i;
				if(isEmpty(top))
					break;

				idx=pop(stack,&top);
			}
			if(arr[idx]<=arr[i])
				push(stack,&top,idx);

		}
		push(stack,&top,i);
		i++;
	}
	while(!isEmpty(top))
	{
		idx=pop(stack,&top);
		next[idx]=size;
	}
}

void Stack::MaximumofMinimum(int arr[],int size,int ans[])
{
	int i,val,len;
	int prev[size],next[size];
	NextSmaller(arr,next,size);
	PrevSmaller(arr,prev,size);

	for(i=0;i<size;i++)
		cout<<next[i]<<" ";

	cout<<endl;

	for(i=0;i<size;i++)
		cout<<prev[i]<<" ";

	cout<<endl;

	for(i=0;i<size;i++)
	{
		len=next[i]-prev[i]-1;
		ans[len]=(ans[len]>arr[i])?ans[len]:arr[i];
	}

	for(i=size-1;i>=0;i--)
	{
		ans[i]=(ans[i]>ans[i+1])?ans[i]:ans[i+1];
	}
}

int main(void)
{
	int size,i;
	Stack ob;
	cout<<"enter size"<<endl;
	cin>>size;
	int arr[size],ans[size+1];
	cout<<"enter the values"<<endl;
	for(i=0;i<size;i++)
		cin>>arr[i];

	for(i=0;i<=size;i++)
		ans[i]=0;

	ob.MaximumofMinimum(arr,size,ans);
	cout<<"output"<<endl;
	for(i=1;i<=size;i++)
		cout<<ans[i]<<" ";
}
