#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		int n;
		int *arr;

	public:
		DP(int);
		int LIS();
};

DP::DP(int size)
{
	n=size;
	arr=new int [n];

	cout<<"enter the values"<<endl;

	for(int i=0;i<n;i++)
		cin>>arr[i];
}

int DP::LIS()
{
	int dp[n];
	int i,j;

	for(i=0;i<n;i++)
		dp[i]=1;

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		}

	}
	int ans=-1;
	for(i=0;i<n;i++)
		if(ans<dp[i])
			ans=dp[i];

	return ans;
}

int main(void)
{
	int n;
	cout<<"enter the size"<<endl;
	cin>>n;
	DP ob(n);
	cout<<"required answer is "<<ob.LIS()<<endl;
}
