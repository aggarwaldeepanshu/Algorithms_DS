#include<iostream>
using namespace std;

int size1=10;
int pairsum[]={15,13,11,10,12,10,9,8,7,5};

class pair_sum
{
	private:
		int size;
		int *arr;

	public:

		pair_sum(int n=5)
		{
			size=n;
			arr=new int[size];
		}
		void get()
		{
			cout<<"Enter the array size"<<endl;
			cin>>size;
			arr=new int[size];
		}
		void array();

		void display()
		{
			cout<<"The required array is: "<<endl;
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}
};

void pair_sum::array()
{
	int i;
	arr[0]=(pairsum[0]+pairsum[1]-pairsum[size-1])/2;
	for(i=1;i<=size-1;i++)
		arr[i]=pairsum[i-1]-arr[0];
}

int main(void)
{
	pair_sum ob;
	ob.get();
	ob.array();
	ob.display();
}
