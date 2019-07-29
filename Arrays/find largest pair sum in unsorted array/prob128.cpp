#include<iostream>
using namespace std;

class sum_pair
{
	private:
		int size,sum;
		int *arr;

	public:
		sum_pair(int n=4)
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
		void find_pair();
		void display()
		{
			cout<<"The required pair sum is: "<<sum<<endl;
		}
};

void sum_pair::find_pair()
{
	int large,max,i;
	max=(arr[0]>arr[1])?arr[0]:arr[1];
	large=(arr[0]<arr[1])?arr[0]:arr[1];
	for(i=2;i<size;i++)
	{
		if(arr[i]>max)
		{
			large=max;
			max=arr[i];
		}
		else if(arr[i]>large)
			large=arr[i];
	}
	sum=large+max;
}

int main(void)
{
	sum_pair ob;
	ob.get();
	ob.find_pair();
	ob.display();
}
