#include<iostream>
using namespace std;

class intersection
{
	private:
		int size1,size2,size3;
		int *arr1,*arr2,*arr3;

	public:

		intersection(int n=4,int m=4,int k=4)
		{
			size1=n;
			size2=m;
			size3=k;
			arr1=new int[size1];
			arr2=new int[size2];
			arr3=new int[size3];
		}
		void get()
		{
			int i;
			cout<<"Enter the first array size"<<endl;
			cin>>size1;
			arr1=new int[size1];
			cout<<"Enter the values of first array"<<endl;
			for(i=0;i<size1;i++)
				cin>>arr1[i];

			cout<<"Enter the second array size"<<endl;
			cin>>size2;
			arr2=new int[size2];
			cout<<"Enter the values of second array"<<endl;
			for(i=0;i<size2;i++)
				cin>>arr2[i];

			cout<<"Enter the third array size"<<endl;
			cin>>size3;
			arr3=new int[size3];
			cout<<"Enter the values of third array"<<endl;
			for(int i=0;i<size3;i++)
				cin>>arr3[i];
		}
		void common_elements();
};

void intersection::common_elements()
{
	int i=0,j=0,k=0;
	while(i<size1 && j<size2 && k<size3)
	{
		if(arr1[i]<arr2[j])
			i++;
		else if(arr1[i]>arr2[j])
			j++;
		else
		{
			if(arr3[k]<arr1[i])
				k++;
			else if(arr3[k]>arr1[i])
				i++;
			else
                           {
				cout<<arr3[k]<<" ";
                                k++;
                           }
		}
	}
}

int main(void)
{
	intersection ob;
	ob.get();
	ob.common_elements();
}
