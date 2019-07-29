#include<iostream>
#include<cstdlib>
#include<climits>
#include<algorithm>
using namespace std;

class sum
{
	private:
		int size;
		int *arr;

	public:

		sum(int n=4)
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
		void sum_close_to_zero();
};

void sum::sum_close_to_zero()
{
	int i,j,sum,val,a=0,b=0;
	i=0;
	j=size-1;
	val=INT_MAX;
	sort(arr,arr+size);
	while(i<j)
	{
		sum=arr[i]+arr[j];
		if(abs(sum)<abs(val))
		{
			val=sum;
			a=i;
			b=j;
		}
		if(sum<0)
			i++;
		else
			j--;
	}
	cout<<"The required pair is: "<<arr[a]<<" "<<arr[b]<<endl;
	cout<<"The required sum is:"<<arr[a]+arr[b]<<endl;
}

int main(void)
{
	sum ob;
	ob.get();
	ob.sum_close_to_zero();
}
