#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		int size,m,n;
		int **cost;

	public:
		DP(int,int,int);
		int find_min();
};

DP::DP(int a,int b,int c)
{
	size=a;
	m=b;
	n=c;
	cost=new int* [size];
	for(int i=0;i<size;i++)
		cost[i]=new int [size];

	cout<<"Enter the cost matrix"<<endl;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			cin>>cost[i][j];
}

int min(int a,int b)
{
	return (a>b)?b:a;
}

int DP::find_min()
{
	int i,j;
	for(i=1;i<size;i++)
		cost[0][i]+=cost[0][i-1];

	for(i=1;i<size;i++)
		cost[i][0]+=cost[i-1][0];
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			cost[i][j]=min(cost[i-1][j-1],min(cost[i-1][j],cost[i][j-1]))+cost[i][j];
		}

	}
	return cost[m][n];
}

int main(void)
{
	int size,n,m;
	cout<<"enter the size and destination"<<endl;
	cin>>size>>m>>n;

	DP ob(size,m,n);
	cout<<"minimum path cost is "<<ob.find_min()<<endl;
}
