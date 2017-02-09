#include<iostream>
#include<cstdlib>
#define max 80
using namespace std;

int *arr2;
int size2;
class sort_array
{
	private:
		int size1;
		int *arr1;

	public:

		sort_array(int n=4)
		{
			size1=n;
			arr1=new int[size1];
		}
		void get()
		{
			cout<<"Enter the first array size"<<endl;
			cin>>size1;
			cout<<"Enter the second array size"<<endl;
			cin>>size2;
			arr1=new int[size1];
			arr2=new int[size2];
			cout<<"Enter the values of first array"<<endl;
			for(int i=0;i<size1;i++)
				cin>>arr1[i];
			cout<<"Enter the values of second array"<<endl;
			for(int i=0;i<size2;i++)
				cin>>arr2[i];
		}
		void q_sort();
		void display()
		{
			cout<<"Sorted arary is: "<<endl;
			for(int i=0;i<size1;i++)
				cout<<arr1[i]<<" "; 
		}
};

int check(int val)
{
	for(int i=0;i<size2;i++)
	{
		if(arr2[i]==val)
			return i;
	}
	return -1;
}

int comparator(const void *a,const void *b)
{
	int l=check(*(int *)a);
	int m=check(*(int *)b);
	if(l!=-1&&m!=-1)
		return (l-m);
	else if(l!=-1&&m==-1)
		return -1;
	else if(l==-1&&m!=-1)
		return 1;
	else
		return (*(int *)a-*(int *)b);
}

void sort_array::q_sort()
{
	qsort(arr1,size1,sizeof(arr1[0]),comparator);
}

int main(void)
{
	sort_array ob;
	ob.get();
	ob.q_sort();
	ob.display();
}
