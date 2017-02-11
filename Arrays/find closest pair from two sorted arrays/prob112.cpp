#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

class closest_pair
{
	private:
		int size1,size2,k;
		int *arr1,*arr2;

	public:

		closest_pair(int n=4,int m=4)
		{
			size1=n;
			size2=m;
			k=2;
			arr1=new int[size1];
			arr2=new int[size2];
		}
		void get()
		{
                        int i;
			cout<<"Enter the first array size"<<endl;
			cin>>size1;
			arr1=new int[size1];
			cout<<"Enter the second array size"<<endl;
			cin>>size2;
			arr2=new int[size2];
			cout<<"Enter the values of first array"<<endl;
			for(i=0;i<size1;i++)
				cin>>arr1[i];
                        cout<<"Enter the values of second array"<<endl;
			for(i=0;i<size2;i++)
				cin>>arr2[i];
			cout<<"Enter the number"<<endl;
			cin>>k;
		}
		void pair();
};

void closest_pair::pair()
{
	int l,m,min,a=-1,b=-1;
	min=INT_MAX;
	l=0;
	m=size2-1;
	while(l<size1&&m>=0)
	{
		if(abs(arr1[l]+arr2[m]-k)<min)
		{
			min=abs(arr1[l]+arr2[m]-k);
			a=l;
			b=m;
		}
		else if(arr1[l]+arr2[m]<k)
			l++;
		else
			m--;
	}
	cout<<"The required pair is: "<<arr1[a]<<" "<<arr2[b]<<endl;
}

int main(void)
{
	closest_pair ob;
	ob.get();
	ob.pair();
}
