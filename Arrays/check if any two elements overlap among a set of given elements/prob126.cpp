#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

class interval
{
	private:
		int size;
		pair <int,int> *arr;
	public:

		void get()
		{
			int a,b;
			cout<<"Enter the array size"<<endl;
			cin>>size;
			arr=new pair<int,int> [size];
			cout<<"Enter the values"<<endl;
			for(int i=0;i<size;i++)
			{
				cin>>arr[i].first>>arr[i].second;
			}
		}
		void interval_overlap();
};

void interval::interval_overlap()
{
	int i,v=0;
	sort(arr,arr+size);
	for(i=1;i<size;i++)
	{
		if(arr[i].first<=arr[i-1].second)
                { 
                        v=1;
			cout<<"("<<arr[i-1].first<<","<<arr[i-1].second<<")"<<" and "<<"("<<arr[i].first<<","<<arr[i].second<<")"<<endl;
                }
	}
        if(v==0)
          cout<<"No such pair"<<endl;
}

int main(void)
{
	interval ob;
	ob.get();
	ob.interval_overlap();
}
