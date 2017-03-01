#include<iostream>
using namespace std;

class replace
{
	private:
		int size;
		int *arr;

	public:

		replace(int n=4)
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
		void multiply();
		void display()
		{
			cout<<"The required array is"<<endl;
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}
};

void replace::multiply()
{
	int i,prev,curr;
	prev=arr[0];
	arr[0]=arr[0]*arr[1];
	for(i=1;i<size-1;i++)
	{
		curr=arr[i];
		arr[i]=prev*arr[i+1];
		prev=curr;
	}
	arr[size-1]=arr[size-1]*prev;
}

int main(void)
{
	replace ob;
	ob.get();
	ob.multiply();
	ob.display();
}
