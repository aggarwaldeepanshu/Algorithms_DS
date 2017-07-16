#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		int SubstringSearch(char [],char []);
};

int searchRecur(char str[],char pat[],int n,int m,int i,int j)
{
	if((j==m && i!=n) || (i==n && j==m))
		return 1;

	if(i==n && j<m)
		return 0;

	if(str[i]==pat[j])
		return searchRecur(str,pat,n,m,i+1,j+1);

	if(str[i]!=pat[j])
		return searchRecur(str,pat,n,m,i+1,j);

}

int String::SubstringSearch(char str[],char pat[])
{
	int i,n,m;
	n=strlen(str);
	m=strlen(pat);
	if(n<m)
		return 0;

	return searchRecur(str,pat,n,m,0,0);
}

int main(void)
{
	int i;
	String ob;
	char str[max1],pat[max1];
	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout<<"enter the pattern"<<endl;
	cin.get(pat,max1);

	if(ob.SubstringSearch(str,pat))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
