#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		int total,n;
		int *coins,*count,*parent;

	public:
		DP(int,int);
		void find_min(void);
		void display();
};

void DP::display()
{
	cout<<"Minimum number of coins needed is "<<count[total]<<endl;

	cout<<"coins needed are:"<<endl;

	int val=total;
	for(int i=0;i<count[total];i++)
	{
		cout<<coins[parent[val]]<<" ";
		val-=coins[parent[val]];
	}
	cout<<endl;
}

void find_min_recur(int total,int coins[],int count[],int parent[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=total;j++)
		{
			if(j<coins[i])
				continue;

			if(count[j]>1+count[j-coins[i]])
			{
				count[j]=1+count[j-coins[i]];
				parent[j]=i;
			}

		}

	}

}

void DP::find_min(void)
{
	find_min_recur(total,coins,count,parent,n);
}

DP::DP(int val,int size)
{
	total=val;
	n=size;
	coins=new int [n];
	count=new int [total+1];
	parent=new int [total+1];
	cout<<"Enter the coins"<<endl;
	for(int i=0;i<n;i++)
		cin>>coins[i];

	for(int i=0;i<=total;i++)
	{
		count[i]=10000;
		parent[i]=-1;
	}
	count[0]=0;
}

int main(void)
{
	int val,size;
	cout<<"enter the size and total value"<<endl;
	cin>>size>>val;
	DP ob(val,size);
	ob.find_min();
	ob.display();
}
