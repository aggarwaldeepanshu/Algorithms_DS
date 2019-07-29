#include<iostream>
#include<algorithm>
using namespace std;

class triplet
{
	private:
		int size,sum;
		int *arr;

	public:

		triplet(int n=4)
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
			cout<<"Enter the sum"<<endl;
			cin>>sum;
		}
		void find_triplet();
};

void triplet::find_triplet()
{
	int i,a,b,val,count=0;
	sort(arr,arr+size);

	for(i=0;i<size-2;i++)
	{
		a=i+1;
		b=size-1;
		while(a<b)
		{
			val=arr[i]+arr[a]+arr[b];
			if(val<sum)
			{
				count+=(b-a);
				a++;
			}
			else
				b--;
		}
	}
	cout<<"Count of triplets: "<<count<<endl;
}

int main(void)
{
	triplet ob;
	ob.get();
	ob.find_triplet();
}
