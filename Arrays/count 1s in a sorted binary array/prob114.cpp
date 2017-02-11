#include<iostream>
using namespace std;

class binary
{
	private:
		int size;
		int *arr;

	public:

		binary(int n=4)
		{
			size=n;
			arr=new int[size];
		}
		void get()
		{
			cout<<"Enter the array size"<<endl;
			cin>>size;
			arr=new int[size];
			cout<<"Enter the values"<<endl;
			for(int i=0;i<size;i++)
				cin>>arr[i];
		}
		void count();
};

int binary_search(int arr[],int low,int high)
{
	int mid;
	if(high==1)
		return high;
	else if(low<=high)
	{
		mid=(low+high)/2;
		if((mid==high||arr[mid+1]!=1)&&arr[mid]==1)
			return mid;
		else if(arr[mid]!=1)
			return binary_search(arr,low,mid-1);
		else if(arr[mid]==1&&arr[mid+1]==1)
			return binary_search(arr,mid+1,high);
	}
	return -1;
}

void binary::count()
{
	int v,val;
	v=binary_search(arr,0,size-1);
	if(v==-1)
		cout<<0<<endl;
	else
		cout<<v+1<<endl;
}

int main(void)
{
	binary ob;
	ob.get();
	ob.count();
}
