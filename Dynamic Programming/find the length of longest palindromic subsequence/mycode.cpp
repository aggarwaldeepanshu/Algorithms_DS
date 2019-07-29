#include<bits/stdc++.h>
using namespace std;

int find_length(string str)
{
	int n,i,j,k;
	n=str.length();
	int lps[n][n];
	for(i=0;i<n;i++)
		lps[i][i]=1;

	for(i=2;i<=n;i++)
	{
		for(j=0;j<n-i+1;j++)
		{
			k=j+i-1;
			if(str[j]==str[k] && i==2)
				lps[j][k]=2;

			else if(str[j]==str[k])
				lps[j][k]=2+lps[j+1][k-1];

			else
				lps[j][k]=max(lps[j+1][k],lps[j][k-1]);
		}

	}
	return lps[0][n-1];
}

int main(void)
{
	string str;
	cout<<"enter the string"<<endl;
	cin>>str;

	int ans=find_length(str);
	cout<<"length of longest subsequence is "<<ans<<endl;
}
