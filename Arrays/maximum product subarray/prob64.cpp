#include<iostream>
using namespace std;

class subarray
{
	private:
		int size;
		int *arr;

	public:

		subarray(int n=4)
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
		void max_product();
};

int minimum(int a,int b)
{
	return (a<b)?a:b;
}

int maximum(int a,int b)
{
	return (a<b)?b:a;
}

void subarray::max_product()
{
	int i,max=1,min=1,max_update=0,val;
	for(i=0;i<size;i++)
	{

		if(arr[i]==0)
		{
			max=1;
			min=1;
		}

		else if(arr[i]>0)
		{
			max=max*arr[i];
			min=minimum(min*arr[i],1);
		}

		else
		{
			val=max;
			max=maximum(min*arr[i],1);
			min=val*arr[i];
		}

		if(max_update<max)
			max_update=max;
	}
	cout<<"Maximum Product is: "<<max_update<<endl;
}

int main(void)
{
	subarray ob;
	ob.get();
	ob.max_product();
}
