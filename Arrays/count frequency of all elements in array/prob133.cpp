#include<iostream>
using namespace std;

class frequency
{
	private:
		int size;
		int *arr;

	public:

		frequency(int n=4)
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
		void count_frequency();
};

void frequency::count_frequency()
{
	int i;
	for(i=0;i<size;i++)
		arr[i]--;

	for(i=0;i<size;i++)
		arr[arr[i]%size]+=size;

	for(i=0;i<size;i++)
		cout<<i+1<<" "<<arr[i]/size<<endl;
}

int main(void)
{
	frequency ob;
	ob.get();
	ob.count_frequency();
}
