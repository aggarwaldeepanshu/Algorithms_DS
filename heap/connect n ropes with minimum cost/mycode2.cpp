#include<iostream>
#include<climits>
#define max 100
using namespace std;

class Heap
{
	public:
		int MinCost(int [],int);
};

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return ;
}

void Heapify(int heap[],int i,int size)
{
	int smallest,l,r;
	smallest=i;
	l=2*i+1;
	r=2*i+2;
	if(l<size && heap[smallest]>heap[l])
		smallest=l;

	if(r<size && heap[smallest]>heap[r])
		smallest=r;

	if(smallest!=i)
	{
		swap(&heap[smallest],&heap[i]);
		Heapify(heap,smallest,size);
	}

}

void BuildHeap(int heap[],int size)
{
	int i;
	for(i=(size-1)/2;i>=0;i--)
		Heapify(heap,i,size);
}

int getMin(int arr[],int *size)
{
	int val=arr[0];
	arr[0]=arr[*size-1];
	(*size)--;
	Heapify(arr,0,*size);
	return val;
}

void PushSum(int arr[],int size,int sum)
{
	arr[0]=sum;
	Heapify(arr,0,size);
}

int Heap::MinCost(int arr[],int size)
{
	int i,j=0,a,b,sum=0;
	int heap[size];
	BuildHeap(arr,size);

	while(1)
	{
		if(size==2)
		{
			a=arr[0];
			b=arr[1];
			heap[j++]=a+b;
			break;
		}

		else if(size>2)
		{
			a=getMin(arr,&size);
			b=arr[0];
			heap[j++]=a+b;
			PushSum(arr,size,a+b);
		}

	}
	for(i=0;i<j;i++)
		sum+=heap[i];

	return sum;
}

int main(void)
{
	Heap ob;
	int i,size,k;

	cout<<"enter the size"<<endl;
	cin>>size;

	int arr[size];

	cout<<"enter the values"<<endl;

	for(i=0;i<size;i++)
		cin>>arr[i];

	k=ob.MinCost(arr,size);
	cout<<"total cost is "<<k<<endl;
}
