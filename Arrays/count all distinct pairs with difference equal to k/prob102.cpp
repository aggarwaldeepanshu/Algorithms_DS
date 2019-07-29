#include<iostream>
#include<algorithm>

using namespace std;

class distinct_pairs
{
	private:
		int size,k;
		int *arr;

	public:

		distinct_pairs(int n=4,int v=2)
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
			cout<<"Enter the difference"<<endl;
			cin>>k;
		}
		void pairs();
};

void distinct_pairs::pairs()
{
	sort(arr,arr+size);
	int a,b,v,count=0;
	a=b=0;
	while(a<size&&b<size)
	{
		v=arr[b]-arr[a];
		if(v==k)
		{
			count++;
			a++;
			b++;
		}
		else if(v>k)
			a++;
		else
			b++;
	}
cout<<"Total number of pairs: "<<count<<endl;
}

int main(void)
{
	distinct_pairs ob;
	ob.get();
	ob.pairs();
}
