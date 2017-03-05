#include<iostream>
using namespace std;

class zeroes
{
	private:
		int size,m;
		int *arr;

	public:

		zeroes(int n=4)
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
			cout<<"Enter the value of m"<<endl;
			cin>>m;
		}
		void find_maximum();
};

void zeroes::find_maximum()
{
	int i,l=0,r=0,count=0,v=0;

	while(l<size&&r<size)
	{
		if(v<=m)
		{
			if(arr[r]==0)
				v++;
			r++;
		}
		if(v>m)
		{
			if(arr[l]==0)
				v--;
			l++;
		}
		if(r-l>count)
		{
			count=r-l;
			i=l;
		}
	}
	for(v=0;v<count;v++)
		if(arr[v+i]==0)
			cout<<v+i<<" ";
}

int main(void)
{
	zeroes ob;
	ob.get();
	ob.find_maximum();
}
