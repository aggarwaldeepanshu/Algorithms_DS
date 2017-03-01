#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class pythagorean
{
	private:
		int size;
		int *arr;

	public:

		pythagorean(int n=4)
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
		void find_triplet();
};

void pythagorean::find_triplet()
{
	int l,r,i,j,v;
	sort(arr,arr+size);
	j=0;
	for(i=0;i<size;i++)
		arr[i]=arr[i]*arr[i];

	for(i=size-1;i>=2;i--)
	{
		l=0;
		r=i-1;
		while(l<r)
		{
			v=arr[l]+arr[r];
			if(v==arr[i])
			{
				cout<<sqrt(arr[l])<<" "<<sqrt(arr[r])<<" "<<sqrt(arr[i])<<endl;
				r--;
				j=1;
			}
			else if(v>arr[i])
				r--;
			else
				l++;
		}
	}
	if(j==0)
		cout<<"No such triplet"<<endl;
}

int main(void)
{
	pythagorean ob;
	ob.get();
	ob.find_triplet();
}
