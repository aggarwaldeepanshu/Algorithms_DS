#include<iostream>
using namespace std;

class wave_form
{
	private:
		int size;
		int *arr;

	public:

		wave_form(int n=4)
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
		void sort();
		void display()
		{
			cout<<"Sorted array is: "<<endl;
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}
};

void wave_form::sort()
{
	int i,temp;
	for(i=0;i<size;i+=2)
	{
		if(arr[i]<arr[i-1])
		{
			temp=arr[i];
			arr[i]=arr[i-1];
			arr[i-1]=temp;
		}
		if(arr[i]<arr[i+1])
		{
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}
	}
}

int main(void)
{
	wave_form ob;
	ob.get();
	ob.sort();
	ob.display();
}
