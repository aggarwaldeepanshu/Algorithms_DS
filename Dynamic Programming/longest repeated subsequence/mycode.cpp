#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		string str;
		int n;

	public:
		DP(string);
		int find_sequence();
};

DP::DP(string str1)
{
	str=str1;
	n=str.length();
}

int DP::find_sequence()
{
	int dp[n+1][n+1];
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			dp[i][j]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(str[i-1]==str[j-1] && i!=j)
				dp[i][j]=dp[i-1][j-1]+1;

			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}

	}
	return dp[n][n];
}

int main(void)
{
	string str;
	cout<<"enter the string"<<endl;
	cin>>str;
	DP ob(str);
	cout<<"max value is "<<ob.find_sequence()<<endl;
}
