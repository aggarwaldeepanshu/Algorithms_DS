#include<iostream>
using namespace std;

class element
{
	private:
		int size;
		int *arr;

	public:

		element(int n=4)
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
		void search_element();
};

void element::search_element()
{
	int i,v;
	v=arr[0];
	for(i=1;i<size;i++)
		v=v^arr[i];
	cout<<"Element that appears once is: "<<v<<endl;
}

int main(void)
{
	element ob;
	ob.get();
	ob.search_element();
}
