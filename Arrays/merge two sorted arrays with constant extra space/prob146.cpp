#include<iostream>
using namespace std;

class merge
{
	private:
		int size1,size2;
		int *arr1,*arr2;

	public:

		merge(int n=4,int m=3)
		{
			size1=n;
			size2=m;
			arr1=new int[size1];
			arr2=new int[size2];
		}
		void get()
		{
			int i;
			cout<<"Enter the first array size"<<endl;
			cin>>size1;
			cout<<"Enter the second array size"<<endl;
			cin>>size2;
			arr1=new int[size1];
			arr2=new int[size2];
			cout<<"Enter the values for first array"<<endl;
			for(i=0;i<size1;i++)
				cin>>arr1[i];

			cout<<"Enter the values for second array"<<endl;
			for(i=0;i<size2;i++)
				cin>>arr2[i];
		}
		void merge_arrays();
		void display()
		{
			cout<<"Arrays after merging are"<<endl;
			int i;
			for(i=0;i<size1;i++)
				cout<<arr1[i]<<" ";
			cout<<endl;
			for(i=0;i<size2;i++)
				cout<<arr2[i]<<" ";
			cout<<endl;
		}
};

void merge::merge_arrays()
{
	int i,j,val;
	for(i=size2-1;i>=0;i--)
	{
		val=arr1[size1-1];
		for(j=size1-2;j>=0&&arr1[j]>arr2[i];j--)
			arr1[j+1]=arr1[j];

		if(j!=size1-2||val>arr2[i])
		{
			arr1[j+1]=arr2[i];
			arr2[i]=val;
		}
	}
}

int main(void)
{
	merge ob;
	ob.get();
	ob.merge_arrays();
	ob.display();
}
