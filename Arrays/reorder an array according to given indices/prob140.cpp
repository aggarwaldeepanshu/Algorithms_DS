#include<iostream>
using namespace std;

class reorder
{
	private:
		int size;
		int *arr,*index;

	public:

		reorder(int n=4)
		{
			size=n;
			arr=new int[size];
			index=new int[size];
		}
		void get()
		{
			int i;
			cout<<"Enter the array size"<<endl;
			cin>>size;
			arr=new int[size];
			cout<<"Enter the values"<<endl;
			for(i=0;i<size;i++)
				cin>>arr[i];
			cout<<"Enter the values of index array"<<endl;
			for(i=0;i<size;i++)
				cin>>index[i];
		}
		void reorder_array();
		void display()
		{
			int i;
			cout<<"Array after Reordering"<<endl;
			for(i=0;i<size;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
			for(i=0;i<size;i++)
				cout<<index[i]<<" ";
		}
};

void reorder::reorder_array()
{
	int i,temp;
	for(i=0;i<size;i++)
	{
		while(index[i]!=i)
		{
			//to update value in array
			temp=arr[index[i]];
			arr[index[i]]=arr[i];
			arr[i]=temp;
			//to update index in index array
			temp=index[index[i]];
			index[index[i]]=index[i];
			index[i]=temp;
		}
	}
}

int main(void)
{
	reorder ob;
	ob.get();
	ob.reorder_array();
	ob.display();
}
