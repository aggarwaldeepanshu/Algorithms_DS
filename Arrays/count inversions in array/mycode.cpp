#include<iostream>
using namespace std;

class inversions
{
	public:
		int inversions_count(int [],int);
};

int _merge(int arr[],int temp[],int low,int mid,int high)
{
	int count=0,i,j,k;
	i=low;
	k=low;
	j=mid+1;
	while(i<=mid && j<=high)
	{
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];

		else
		{
			temp[k++]=arr[j++];
			count+=(mid-i+1);
		}

	}

	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}

	while(j<=high)
	{
		temp[k++]=arr[j++];
	}

	for(i=low;i<=high;i++)
		arr[i]=temp[i];

	return count;
}

int merge(int arr[],int temp[],int low,int high,int size)
{
	int count=0;
	if(low<high)
	{
		int mid=(low+high)/2;
		count=merge(arr,temp,low,mid,size);
		count+=merge(arr,temp,mid+1,high,size);

		count+=_merge(arr,temp,low,mid,high);
	}
	return count;
}

int inversions::inversions_count(int arr[],int size)
{
	int *temp=new int [size];
	return merge(arr,temp,0,size-1,size);
}

int main(void)
{
	inversions ob;
	int n,i;
	cout<<"enter the size"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the values"<<endl;

	for(i=0;i<n;i++)
		cin>>arr[i];

	int count=ob.inversions_count(arr,n);
	cout<<"count is "<<count<<endl;
}
