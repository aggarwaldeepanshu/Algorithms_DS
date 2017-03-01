#include<iostream>
using namespace std;

class remove
{
	private:
		int size,k;
		int *arr;

	public:

		remove(int n=4)
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
			cout<<"Enter the element to remove"<<endl;
			cin>>k;
		}
		void remove_element();
		void display()
		{
			cout<<"Array after deletion is"<<endl;
			for(int i=0;i<size-1;i++)
				cout<<arr[i]<<" ";
		}
};

void remove::remove_element()
{
	int i,curr,prev;
	prev=arr[size-1];
	for(i=size-2;i>=0;i--)
	{
		curr=arr[i];
		if(arr[i]==k)
		{
			arr[i]=prev;
			break;
		}
		else
		{
			arr[i]=prev;
			prev=curr;
		}
	}
}

int main(void)
{
	remove ob;
	ob.get();
	ob.remove_element();
	ob.display();
}
