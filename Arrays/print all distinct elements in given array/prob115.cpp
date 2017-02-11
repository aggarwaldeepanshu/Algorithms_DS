#include<iostream>
#include<set>
using namespace std;

class elements
{
	private:
		int size;
		int *arr;

	public:

		elements(int n=4)
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
		void distinct_elements();
};

void elements::distinct_elements()
{
	int i;
	set <int> s;
	set <int>::iterator it;
	for(i=0;i<size;i++)
		s.insert(arr[i]);
	for(it=s.begin();it!=s.end();it++)
		cout<<*it<<" ";
}

int main(void)
{
	elements ob;
	ob.get();
	ob.distinct_elements();
}
