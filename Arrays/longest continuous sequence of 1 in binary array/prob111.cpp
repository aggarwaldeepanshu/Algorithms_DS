#include<iostream>
using namespace std;

class longest_sequence
{
	private:
		int size;
		int *arr;

	public:

		longest_sequence(int n=4)
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
		void continuous_sequence();
};

void longest_sequence::continuous_sequence()
{
	int i=0,a=-1,b=-1,count,max=-1,v;
	while(i<size)
	{
		count=0;
		if(arr[i]==1)
			i++;
		else if(arr[i]==0)
		{
			if(b==-1&&a!=-1)
				count=i;

			else if(a!=-1&&b!=-1)
				count=i-b-1;

			if(count>max)
			{
				max=count;
				v=i;
			}

			b=a;
			a=i;
			i++;
		}
	}
	cout<<"The required index is: "<<v<<endl;
}

int main(void)
{
	longest_sequence ob;
	ob.get();
	ob.continuous_sequence();
}
