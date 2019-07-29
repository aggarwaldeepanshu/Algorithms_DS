#include<iostream>
#include<climits>
#define max 100
using namespace std;

struct element
{
	int data;
	int row;
	int index;
};

class Heap
{
	public:
		void SortedOrder(int [][max],int [],int);
};

void swap(struct element *a,struct element *b)
{
	struct element temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return ;
}

void Heapify(struct element heap[],int i,int size)
{
	int smallest,l,r;
	smallest=i;
	l=2*i+1;
	r=2*i+2;
	if(l<size && heap[smallest].data>heap[l].data)
		smallest=l;

	if(r<size && heap[smallest].data>heap[r].data)
		smallest=r;

	if(smallest!=i)
	{
		swap(&heap[smallest],&heap[i]);
		Heapify(heap,smallest,size);
	}

}

void BuildHeap(struct element heap[],int size)
{
	int i;
	for(i=(size-1)/2;i>=0;i--)
		Heapify(heap,i,size);
}

void Heap::SortedOrder(int arr[][max],int ans[],int size)
{
	int i,j=0;
	struct element heap[size];

	for(i=0;i<size;i++)
	{
		heap[i].data=arr[i][0];
		heap[i].index=1;
		heap[i].row=i;
	}

	BuildHeap(heap,size);
	for(j=0;j<size*size;j++)
	{
		ans[j]=heap[0].data;

		if(heap[0].index<size)
		{
			heap[0].data=arr[heap[0].row][heap[0].index];
			heap[0].index++;
		}

		else
			heap[0].data=INT_MAX;

		Heapify(heap,0,size);

	}
}

int main(void)
{
	Heap ob;
	int i,j,size;
	cout<<"enter the size"<<endl;
	cin>>size;

	int arr[max][max],ans[size*size];
	cout<<"enter the values"<<endl;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			cin>>arr[i][j];

	ob.SortedOrder(arr,ans,size);
	cout<<"sorted order is"<<endl;
	for(i=0;i<size*size;i++)
		cout<<ans[i]<<" ";
}
