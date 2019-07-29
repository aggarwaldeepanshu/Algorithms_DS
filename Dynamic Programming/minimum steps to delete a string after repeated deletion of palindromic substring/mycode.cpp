#include<bits/stdc++.h>
using namespace std;

int find_steps(string str)
{
	int n,i,j,k;
	n=str.length();

		int dp[n+1][n+1];
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			dp[i][j]=0;

	for(i=1;i<=n;i++)
	{
		for(j=0,k=i-1;k<n;j++,k++)
		{
			if(i==1)
				dp[j][k]=1;

			else
			{
				dp[j][k]=1+dp[j+1][k];
				if(str[j]==str[j+1])
					dp[j][k]=min(1+dp[j+2][k],dp[j][k]);

				for(int l=j+2;l<=k;l++)
					if(str[j]==str[l])
						dp[j][k]=min(dp[j+1][l-1]+dp[l+1][k],dp[j][k]);

			}

		}

	}
	return dp[0][n-1];
}

int main(void)
{
	string str;
	cout<<"enter the string"<<endl;
	cin>>str;

	int ans=find_steps(str);
	cout<<"required number of steps are "<<ans<<endl;
}
