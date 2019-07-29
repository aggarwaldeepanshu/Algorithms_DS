#include<iostream>
#include<unordered_map>
using namespace std;

class map
{
	private:
		int size,k;
		int *arr;
		unordered_map <int,int> hash;
	public:
		void get()
		{
			cout<<"Enter the array size"<<endl;
			cin>>size;
			cout<<"Enter the values"<<endl;
			arr=new int[size];
			for(int i=0;i<size;i++)
				cin>>arr[i];
			cout<<"Enter the value of k"<<endl;
			cin>>k;
		}
		void duplicate();
};

void map::duplicate()
{
	int i,v=0;
	for(i=0;i<k;i++)
		hash[arr[i]]=i;

	while(i<size)
	{
		if(hash[arr[i]])
		{
			v=1;
			break;
		}
		else
		{
			hash[arr[i]]=i;
			hash.erase(arr[i-k]);
		}
		i++;
	}
	if(v==1)
		cout<<"True"<<endl;
	else
		cout<<"false"<<endl;
}

int main(void)
{
	map ob;
	ob.get();
	ob.duplicate();
}
