#include<iostream>
#include<cstring>
using namespace std;

class queue
{
	public:
		void LargestMultiple(int [],int);
};

void SortArray(int arr[],int size)
{
	int i,j=0,count[10];
	for(i=0;i<10;i++)
		count[i]=0;

	for(i=0;i<size;i++)
		count[arr[i]]++;

	for(i=0;i<=9;i++)
	{
		while(count[i]>0)
		{
			arr[j]=i;
			j++;
			count[i]--;
		}
	}
	return ;
}

void queue::LargestMultiple(int arr[],int size)
{
	int sum=0,i,a=-1,b=-1;

	for(i=0;i<size;i++)
		sum+=arr[i];

	SortArray(arr,size);

	if(sum%3==0)
		return ;

	if(sum%3==1)
	{
		for(i=0;i<size;i++)
		{
			if(arr[i]%3==1)
			{
				arr[i]=-1;
				return ;
			}

			if(arr[i]%3==2)
			{
				if(a==-1)
					a=i;
				else if(b==-1)
					b=i;
			}
		}
	}

	else if(sum%3==2)
	{
		for(i=0;i<size;i++)
		{
			if(arr[i]%3==2)
			{
				arr[i]=-1;
				return ;
			}

			if(arr[i]%3==1)
			{
				if(a==-1)
					a=i;
				else if(b==-1)
					b=i;
			}
		}
	}
	if(a!=-1 && b!=-1)
	{
		arr[a]=-1;
		arr[b]=-1;
		return ;
	}
	else
	{
		cout<<"no multiple of 3 can be formed"<<endl;
		memset(arr,-1,size-1);
		return ;
	}
}

int main(void)
{
	queue ob;
	int i,size;
	cout<<"enter the size"<<endl;
	cin>>size;
	int arr[size];

	cout<<"enter the values"<<endl;
	for(int i=0;i<size;i++)
		cin>>arr[i];

	ob.LargestMultiple(arr,size);
	cout<<"largest multiple is"<<endl;
	for(i=size-1;i>=0;i--)
	{
		if(arr[i]!=-1)
			cout<<arr[i];
	}
}
