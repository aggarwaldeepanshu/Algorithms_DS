#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		int n;
		int *arr;

	public:
		DP(int);
		int rod_cut();
};

DP::DP(int size)
{
	n=size;
	arr=new int [n];

	cout<<"enter the values"<<endl;

	for(int i=0;i<n;i++)
		cin>>arr[i];
}

int DP::rod_cut()
{
	int dp[n+1];
	int i,j;

	//for(i=0;i<n;i++)
	//dp[i]=1;
	dp[0]=0;
	int val;
	for(i=1;i<=n;i++)
	{
		val=INT_MIN;
		for(j=0;j<i;j++)
		{
			val=max(val,arr[j]+dp[i-j-1]);
		}
		dp[i]=val;
	}

	return dp[n];
}

int main(void)
{
	int n;
	cout<<"enter the size"<<endl;
	cin>>n;
	DP ob(n);
	cout<<"required answer is "<<ob.rod_cut()<<endl;
}
