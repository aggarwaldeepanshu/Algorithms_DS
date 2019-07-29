#include<iostream>
#include<set>
#define max 500
using namespace std;

class median
{
	private:
		set<int> arr;
	public:

		void find_median();
};

void median::find_median()
{
	int n,size=0,v;
	set <int> ::iterator it;
	set <int> ::iterator it1;
	cout<<"Enter the number"<<endl<<"Enter -1 to exit"<<endl;
	cin>>n;
	while(n!=-1)
	{
		size+=1;
		arr.insert(n);
		it=arr.begin();
		it1=arr.begin();
		if(size==1)
		{
			cout<<*it<<" ";
		}
		else if(size%2!=0)
		{
			advance(it,size/2);
			cout<<*it<<" ";
		}
		else
		{
			advance(it,size/2);
			advance(it1,size/2-1);
			cout<<(*it+*it1)/2<<" ";
		}
		cout<<endl;
		cin>>n;
	}

}

int main(void)
{
	median ob;
	ob.find_median();
}
