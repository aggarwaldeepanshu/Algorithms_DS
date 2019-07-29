#include<iostream>
using namespace std;

class integers
{
	private:
		int size;
		int *arr,*hash;

	public:

		integers(int n=4)
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
			hash=new int[size];
		}
		void repeating_elements();
};

void integers::repeating_elements()
{
	int i,j,k,min=-1;
	for(i=0;i<size;i++)
		hash[i]=-1;

	for(i=size-1;i>=0;i--)
	{
		j=0;
		k=0;
		while(hash[j]!=-1)
		{
			j=(arr[i]+k*k)%11;
			if(hash[j]==arr[i])
			{
				min=i;
				break;
			}
			else
				k++;
		}
		if(hash[j]==-1)
			hash[j]=arr[i];
	}
	cout<<"The repeating element is: "<<arr[min]<<endl;
}

int main(void)
{
	integers ob;
	ob.get();
	ob.repeating_elements();
}
