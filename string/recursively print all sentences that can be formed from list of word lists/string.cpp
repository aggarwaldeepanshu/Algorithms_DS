#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void printSentence(string [][max1],int,int);
};

void printRecur(string str[][max1],string ans[],int index,int pos,int r,int c)
{
	int j;

	ans[index]=str[index][pos];

	if(index==r-1)
	{
		for(j=0;j<r;j++)
			cout<<ans[j]<<" ";

		cout<<endl;
		return ;
	}

	for(j=0;j<c;j++)
	{
		if(str[index+1][j]!="")
			printRecur(str,ans,index+1,j,r,c);
	}

}

void String::printSentence(string str[][max1],int r,int c)
{
	int i,j;
	string ans[max1];
	for(i=0;i<c;i++)
	{
		if(str[0][i]!="")
			printRecur(str,ans,0,i,r,c);
	}
}

int main(void)
{
	int i,j,r,c;
	cout<<"enter number of rows and columns"<<endl;
	cin>>r>>c;

	String ob;
	string str[max1][max1];

	cout<<"enter strings"<<endl;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>str[i][j];
		}
	}

	ob.printSentence(str,r,c);
}
