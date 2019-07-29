#include<bits/stdc++.h>
using namespace std;

class DP
{
	private:
		string str1,str2;
		int n,m;
		int **table;

	public:
		DP(string,string);
		int min_edits();
};

DP::DP(string a,string b)
{
	str1=a;
	str2=b;
	n=str1.length();
	m=str2.length();
	table=new int* [n+1];
	for(int i=0;i<=n;i++)
		table[i]=new int [m+1];
}

int DP::min_edits()
{
	int i,j;
	table[0][0]=0;

	for(i=1;i<=n;i++)
		table[i][0]=table[i-1][0]+1;

	for(i=1;i<=m;i++)
		table[0][i]=table[0][i-1]+1;

	int val;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			val=min(table[i-1][j-1],min(table[i-1][j],table[i][j-1]));
			if(str1[i]==str2[j])
				table[i][j]=val;

			else
				table[i][j]=val+1;
		}

	}
	return table[n][m];
}

int main(void)
{
	string str1,str2;
	cout<<"enter the string1"<<endl;
	cin>>str1;

	cout<<"enter the string2"<<endl;
	cin>>str2;

	DP ob(str1,str2);
	cout<<"minimum edits required is "<<ob.min_edits()<<endl;

}
