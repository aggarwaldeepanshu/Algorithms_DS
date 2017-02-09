#include<iostream>
#include<cstdlib>
using namespace std;

class quicksort
{
	private:
		int size;
		int *arr;

	public:

		quicksort(int n=4)
                {
			size=n;
			arr=new int[size];
		}
		void get(){
			cout<<"Enter the array size"<<endl;
			cin>>size;
			arr=new int[size];
			cout<<"Enter the values"<<endl;
			for(int i=0;i<size;i++)
				cin>>arr[i];
		}
		void q_sort();

		void display()
		{
			cout<<"Sorted array is:"<<endl;
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}
};

int comparator(const void *a,const void *b)
{
	int l=*(int *)a;
	int m=*(int *)b;
	if((l&1)&&(m&1))
		return (m-l);
	else if(!(l&1)&&!(m&1))
		return (l-m);
	else if(!(l&1))
		return 1;
	else
		return -1;
}

void quicksort::q_sort()
{
	qsort(arr,size,sizeof(arr[0]),comparator);
}

int main(void)
{
	quicksort ob;
	ob.get();
	ob.q_sort();
	ob.display();
}
