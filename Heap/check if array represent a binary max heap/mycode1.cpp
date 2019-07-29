#include<iostream>
using namespace std;

class Heap
{
	public:
		int CheckifHeap(int [],int);
};

int Heap::CheckifHeap(int arr[],int size)
{
	int n,i;

	for(i=0;i<=(size-2)/2;i++)
	{
		if(arr[i]<arr[2*i+1] || arr[i]<arr[2*i+2])
			return 0;
	}

	return 1;
}

int main(void)
{
	Heap ob;
	int i,size;
	cout<<"enter the size"<<endl;
	cin>>size;

	int arr[size];
	cout<<"enter the values"<<endl;
	for(i=0;i<size;i++)
		cin>>arr[i];

	if(ob.CheckifHeap(arr,size))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
