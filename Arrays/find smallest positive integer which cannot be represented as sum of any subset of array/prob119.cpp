#include<iostream>
using namespace std;

class subset
{
	private:
		int size,k;
		int *arr;

	public:

		subset(int n=4)
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
		void smallest_integer();
		void display()
		{
			cout<<"The smallest integer is: "<<k<<endl;
		} 
};

void subset::smallest_integer()
{
	int i;
	k=1;
	for(i=0;i<size;i++)
	{
		if(k<arr[i])
			break;
		else
			k+=arr[i];
	}
}

int main(void)
{
	subset ob;
	ob.get();
	ob.smallest_integer();
	ob.display();
}
