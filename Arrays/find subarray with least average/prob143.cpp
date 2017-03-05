#include<iostream>
using namespace std;

class average
{
	private:
		int size,k;
		int *arr;

	public:

		average(int n=4)
		{
			size=n;
			arr=new int[size];
			k=2;
		}
		void get()
		{
			cout<<"Enter the array size"<<endl;
			cin>>size;
			arr=new int[size];
			cout<<"Enter the values"<<endl;
			for(int i=0;i<size;i++)
				cin>>arr[i];
			cout<<"Enter the value of k"<<endl;
			cin>>k;
		}
		void minimum_average();
};

void average::minimum_average()
{
	int i,sum=0,min,a,b;
	for(i=0;i<k;i++)
		sum+=arr[i];

	min=sum;
	a=0;
	b=k-1;

	for(i=k;i<size;i++)
	{
		sum=sum+arr[i]-arr[i-k];
		if(sum<min)
		{
			min=sum;
			a=i-k+1;
			b=i;
		}
	}

	cout<<"Minimum Average is: "<<min/4<<endl;
	cout<<"and it lies in-- "<<a<<" and "<<b<<" range"<<endl;
}

int main(void)
{
	average ob;
	ob.get();
	ob.minimum_average();
}
