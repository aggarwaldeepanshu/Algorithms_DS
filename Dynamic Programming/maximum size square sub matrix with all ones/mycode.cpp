#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		int r,c;
		int **mat;

	public:
		DP(int,int);
		int max_size();
};

DP::DP(int row,int col)
{
	r=row;
	c=col;
	mat=new int* [r];
	for(int i=0;i<r;i++)
		mat[i]=new int [c];

	cout<<"enter the values"<<endl;

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>mat[i][j];
}

int DP::max_size()
{
	int dp[r][c];
	int i,j;

	for(i=0;i<r;i++)
		dp[i][0]=mat[i][0];

	for(i=0;i<c;i++)
		dp[0][i]=mat[0][i];

	for(i=1;i<r;i++)
	{
		for(j=1;j<c;j++)
		{
			if(mat[i][j]==1)
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;

			else
				dp[i][j]=0;
		}

	}
	int ans=dp[0][0];

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(ans < dp[i][j])
			{
				ans=dp[i][j];
			}
		}
	}

	return ans;
}

int main(void)
{
	int r,c;
	cout<<"enter the number of rows and columns"<<endl;
	cin>>r>>c;
	DP ob(r,c);
	cout<<"required answer is "<<ob.max_size()<<endl;
}
