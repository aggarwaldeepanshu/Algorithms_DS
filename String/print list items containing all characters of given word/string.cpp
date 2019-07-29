#include<bits/stdc++.h>
#define max1 256
#define max2 1000
using namespace std;

class String
{
	public:
		void PrintList(char [],char []);
};

int findWord(char str[],char pat[],int n)
{
	int i,m,count=0;
	m=strlen(pat);
	char hash1[max1]={0};
	char hash2[max1]={0};
	for(i=0;i<m;i++)
	{
		hash1[pat[i]]++;
		hash2[pat[i]]=0;
	}

	for(i=0;i<n;i++)
	{
		if(hash1[str[i]]!=0)
		{
			if(hash2[str[i]]==-1)
				continue;

			else if(hash1[str[i]]==hash2[str[i]])
				hash2[str[i]]=-1;

			else if(hash1[str[i]]>hash2[str[i]])
				hash2[str[i]]++;
		}
	}

	i=0;
	while(i<m)
	{

		if((hash2[pat[i]]==0) || (hash2[pat[i]]<hash1[pat[i]] && hash2[pat[i]]!=-1))
			return 0;

		i++;
	}
	if(i==m)
		return 1;
}

void String::PrintList(char str[],char pat[])
{
	int n,m,i,start=0,v;
	n=strlen(str);

	for(i=0;i<n;i++)
	{
		while(str[i]!=' ' && i<n)
			i++;

		v=findWord(str+start,pat,i-start);
		if(v==1)
		{
			m=i-start;
			while(m>0)
			{
				cout<<str[start];
				start++;
				m--;
			}
			cout<<endl;
		}
		start=i+1;
	}
}

int main(void)
{
	String ob;
	int i;
	char str[max2],pattern[max2];

	cout<<"enter the word"<<endl;
	cin.get(pattern,max2);

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout<<"enter the string"<<endl;
	cin.get(str,max2);

	ob.PrintList(str,pattern);
}
