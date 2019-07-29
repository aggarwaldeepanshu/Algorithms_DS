#include<iostream>
using namespace std;

class radix_sort
{
	private:
		int size;
		int *arr;
		int *output;
	public:
		radix_sort(int n=4)
		{
			size=n;
			arr=new int[size];
			output=new int[size];
		}
		void get()
		{
			cout<<"Enter the array size"<<endl;
			cin>>size;
			arr=new int[size];
			output=new int[size];
			cout<<"Enter the values"<<endl;
			for(int i=0;i<size;i++)
				cin>>arr[i];

		}
		void counting_sort(int exp);
		void radix();
		void display()
		{
			for(int i=0;i<size;i++)
				cout<<output[i]<<" ";
		}
};

void radix_sort::counting_sort(int exp)
{
	int i;
	int temp[10];
	for(i=0;i<10;i++)
		temp[i]=0;

	for(i=0;i<size;i++)
		temp[(arr[i]/exp)%10]+=1;

	for(i=1;i<10;i++)
		temp[i]+=temp[i-1];

	for(i=size-1;i>=0;i--){
		output[temp[(arr[i]/exp)%10]-1]=arr[i];
		temp[(arr[i]/exp)%10]-=1;
	}
	for(i=0;i<size;i++)
		arr[i]=output[i];
}

void radix_sort::radix()
{
	int i,max,exp;
	max=arr[0];
	for(i=1;i<size;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	for(exp=1;max/exp>0;exp*=10)
		counting_sort(exp);
}

int main(void)
{
	radix_sort ob;
	ob.get();
	ob.radix();
	ob.display();
}
