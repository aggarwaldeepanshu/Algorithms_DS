#include<iostream>
using namespace std;

class Heap
{
	public:
		void SortArray(int [],int,int);
};

void swap(int *i,int *j)
{
	int temp;
	temp=*i;
	*i=*j;
	*j=temp;
	return ;
}

void Heapify(int heap[],int i,int size)
{
	int largest,l,r;
	largest=i;
	l=2*i+1;
	r=2*i+2;

	if(l<size && heap[largest]>heap[l])
		largest=l;

	if(r<size && heap[largest]>heap[r])
		largest=r;

	if(largest!=i)
	{
		swap(&heap[largest],&heap[i]);
		Heapify(heap,largest,size);
	}
}

void BuildHeap(int heap[],int size)
{
	int i;

	for(i=(size-1)/2;i>=0;i--)
		Heapify(heap,i,size);

}

int ReplaceMin(int heap[],int size,int key)
{
	int val;
	val=heap[0];
	heap[0]=key;
	Heapify(heap,0,size);
	return val;
}

int ExtractMin(int heap[],int *size)
{
	int i;
	int val=heap[0];

	if(*size>1)
	{
		heap[0]=heap[*size-1];
		(*size)--;
		i=*size;
		Heapify(heap,0,i+1);
	}

	return val;
}

void Heap::SortArray(int arr[],int size,int k)
{
	int i,j=0,n;
	int heap[k+1];
	n=k+1;

	for(i=0;i<=k;i++)
		heap[i]=arr[i];


	BuildHeap(heap,n);

	for(i=n;j<size;i++)
	{
		if(i<size)
			arr[j]=ReplaceMin(heap,n,arr[i]);
		else
			arr[j]=ExtractMin(heap,&n);

		j++;
	}
}

int main(void)
{
	Heap ob;
	int size,i,k;
	cout<<"enter the size"<<endl;
	cin>>size;

	int arr[size];

	cout<<"enter the values"<<endl;

	for(i=0;i<size;i++)
		cin>>arr[i];

	cout<<"enter k"<<endl;
	cin>>k;

	ob.SortArray(arr,size,k);
	cout<<"the sorted array is"<<endl;

	for(i=0;i<size;i++)
		cout<<arr[i]<<" ";
}
