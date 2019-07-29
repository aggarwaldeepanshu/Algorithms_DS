#include<iostream>
using namespace std;

class zeroes
{
	private:
		int size;
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
		}
		void move_zeroes();
		void display()
		{
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}
};

void zeroes::move_zeroes()
{
	int i,count=0,temp;
	for(i=0;i<size;i++)
	{
		if(arr[i]!=0)
		{
			arr[count]=arr[i];
			count++;
		}
	}
	while(count<size)
		arr[count++]=0;
}

int main(void)
{
	zeroes ob;
	ob.get();
	ob.move_zeroes();
	ob.display();
}
