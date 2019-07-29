#include<iostream>
using namespace std;

class subarray
{
	private:
		int size,k;
		int *arr;

	public:

		subarray(int n=4)
		{
			size=n;
			arr=new int[size];
			k=0;
		}
		void get()
		{
			cout<<"Enter the array size"<<endl;
			cin>>size;
			arr=new int[size];
			cout<<"Enter the values"<<endl;
			for(int i=0;i<size;i++)
				cin>>arr[i];
			cout<<"Enter the number"<<endl;
			cin>>k;
		}
		void sum_subarray();
		~subarray()
		{
			delete [] arr;
		}
};

void subarray::sum_subarray()
{
	int i,min=size-1,a,b,sum;
	a=b=0;
	sum=0;
	while(b<size)
	{
		while(sum<=k&&b<size)
			sum+=arr[b++];
		while(sum>k&&a<size)
		{
			if((b-a)<min)
				min=b-a;
			sum-=arr[a++];
		}
	}
	cout<<"Minimum length is: "<<min<<endl;
}

int main(void)
{
	subarray ob;
	ob.get();
	ob.sum_subarray();
}
