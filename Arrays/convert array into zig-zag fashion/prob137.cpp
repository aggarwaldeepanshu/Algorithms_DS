#include<iostream>
using namespace std;

class zig_zag
{
	private:
		int size;
		int *arr;

	public:

		zig_zag(int n=4)
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
		void convert_array();
		void display()
		{
			cout<<"Array after reordering is:"<<endl;
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}
};

void swap(int arr[],int i)
{
	int temp;
	temp=arr[i];
	arr[i]=arr[i+1];
	arr[i+1]=temp;
}

void zig_zag::convert_array()
{
	int i,temp;
	for(i=0;i<size-1;i++)
	{
		if(i%2==0)
		{
			if(arr[i]>arr[i+1])
			{
				swap(arr,i);
			}
		}
		else
		{
			if(arr[i]<arr[i+1])
			{
				swap(arr,i);
			}
		}
	}
}

int main(void)
{
	zig_zag ob;
	ob.get();
	ob.convert_array();
	ob.display();
}
