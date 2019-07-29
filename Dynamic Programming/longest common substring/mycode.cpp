#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		string str1,str2;
		int n,m;

	public:
		DP(string,string);
		int find_lcs();
};

DP::DP(string a,string b)
{
	str1=a;
	str2=b;
	n=str1.length();
	m=str2.length();
}

int DP::find_lcs()
{
	int dp[n+1][m+1];
	int i,j;
	for(i=0;i<=n;i++)
		dp[0][i]=0;

	for(i=0;i<=m;i++)
		dp[i][0]=0;

	int ans=INT_MIN;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				ans=max(ans,dp[i][j]);
			}

			else
				dp[i][j]=0;
		}

	}
	return ans;
}

int main(void)
{
	string a,b;
	cout<<"enter the strings"<<endl;
	cin>>a>>b;
	DP ob(a,b);
	cout<<"required answer is "<<ob.find_lcs()<<endl;
}
