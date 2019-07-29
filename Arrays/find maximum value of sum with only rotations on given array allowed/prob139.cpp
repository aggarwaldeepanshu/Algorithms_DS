#include<iostream>
using namespace std;
class rotations
{
	private:
		int size;
		int *arr;

	public:

		rotations(int n=4)
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
		void maximum_sum();
};

void rotations::maximum_sum()
{
	int i,val=0,max=0,sum=0,v;
	for(i=0;i<size;i++)
	{
		val+=arr[i]*i;
		sum+=arr[i];
	}
	max=val;
	for(i=1;i<size;i++)
	{
		val+=(sum-size*arr[size-i]);
		if(val>max)
			max=val;
	}
	cout<<"Maximum sum is: "<<max<<endl;
}

int main(void)
{
	rotations ob;
	ob.get();
	ob.maximum_sum();
}
