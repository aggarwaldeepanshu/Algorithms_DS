#include<iostream>
#include<algorithm>
using namespace std;

class unsorted
{
	private:
		int size1,size2;
		int *arr1,*arr2;

	public:

		void get()
		{
			cout<<"Enter the first array size"<<endl;
			cin>>size1;
			arr1=new int[size1];
			cout<<"Enter the values"<<endl;
			for(int i=0;i<size1;i++)
				cin>>arr1[i];

			cout<<"Enter the second array size"<<endl;
			cin>>size2;
			arr2=new int[size2];
			cout<<"Enter the values"<<endl;
			for(int i=0;i<size2;i++)
				cin>>arr2[i];
		}
		void union_intersection();
};

int binary_search(int arr[],int low,int high,int key)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
			return binary_search(arr,low,mid-1,key);
		else
			return binary_search(arr,mid+1,high,key);
	}
	return -1;
}

void unsorted::union_intersection()
{
	int i,j,v,k;
	int *uni,*inter;
	if(size1>size2)
	{
		int *arr;
		arr=arr1;
		arr1=arr2;
		arr2=arr;

		j=size1;
		size1=size2;
		size2=j;
	}
	uni=new int[size1+size2];
	inter=new int[size1];
	k=0;
	sort(arr1,arr1+size1);
	for(i=0;i<size1;i++)
		uni[i]=arr1[i];
	for(j=0;j<size2;j++)
	{
		v=binary_search(arr1,0,size1,arr2[j]);
		if(v==-1)
		{
			uni[i]=arr2[j];
			i++;
		}
		else
		{
			inter[k]=arr2[j];
			k++;
		}
	}
	cout<<"Arrays after union and intersection are respectively"<<endl;
	for(j=0;j<i;j++)
		cout<<uni[j]<<" ";
	cout<<endl;
	for(j=0;j<k;j++)
		cout<<inter[j]<<" ";
}

int main(void)
{
	unsorted ob;
	ob.get();
	ob.union_intersection();
}
