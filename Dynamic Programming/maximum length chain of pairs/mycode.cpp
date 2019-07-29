#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		int n;
		vector<pair<int,int> > arr;

	public:
		DP(int);
		int max_length();
};

DP::DP(int size)
{
	n=size;

	cout<<"enter the values"<<endl;

	int a,b;

	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		arr.push_back(make_pair(a,b));
	}

}

int DP::max_length()
{
	int dp[n+1];
	int i,j;
	for(i=0;i<=n;i++)
		dp[i]=1;

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[j].second<arr[i].first && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		}

	}

	int ans=-1;
	for(i=0;i<=n;i++)
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
	cout<<"required answer is "<<ob.max_length()<<endl;
}
