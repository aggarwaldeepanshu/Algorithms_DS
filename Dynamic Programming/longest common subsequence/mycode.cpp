#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		string str1,str2;
		int n1,n2;

	public:
		DP(string,string);
		int find_lcs();
};

DP::DP(string a,string b)
{
	str1=a;
	str2=b;
	n1=str1.length();
	n2=str2.length();
}

int DP::find_lcs()
{
	int **table=new int* [n1+1];
	int i,j;
	for(i=0;i<=n1;i++)
		table[i]=new int [n2+1];

	for(i=0;i<=n1;i++)
		table[i][0]=0;

	for(i=0;i<=n2;i++)
		table[0][i]=0;

	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			if(str1[i]==str2[j])
				table[i][j]=table[i-1][j-1]+1;

			else
				table[i][j]=max(table[i-1][j],table[i][j-1]);
		}
	}
	return table[n1][n2];
}

int main(void)
{
	string str1,str2;
	cout<<"enter the string 1"<<endl;
	cin>>str1;

	cout<<"enter the string 2"<<endl;
	cin>>str2;

	DP ob(str1,str2);
	cout<<"longest common subsequence is "<<ob.find_lcs()<<endl;
}
