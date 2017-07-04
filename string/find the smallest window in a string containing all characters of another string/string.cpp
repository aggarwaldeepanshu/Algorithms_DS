#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		void SmallestWindow(char [],char[]);
};

void String::SmallestWindow(char str[],char pat[])
{
	int i,n,m,k=-1,j=0,count=0,length=INT_MAX,a;
	n=strlen(str);
	m=strlen(pat);

	int hash1[max]={0};
	int hash2[max]={0};

	for(i=0;i<m;i++)
		hash1[pat[i]]++;

	for(i=0;i<n;i++)
	{
		hash2[str[i]]++;

		if(hash1[str[i]]!=0 && hash2[str[i]]<=hash1[str[i]])
			count++;

		if(count==m)
		{
			while(hash1[str[j]]==0 || hash2[str[j]]>hash1[str[j]])
			{
				if(hash2[str[j]]>hash1[str[j]])
				{
					hash2[str[j]]--;
					j++;
				}
			}
			k=i-j+1;
			if(k<length)
			{
				length=k;
				a=j;
			}
		}
	}
	cout<<"minimum length is "<<length<<endl;
	i=length;
	for(k=a;i>0;i--)
	{
		cout<<str[k];
		k++;
	}
}

int main(void)
{
	String ob;
	int i=0;
	char str[max],pattern[max],ch;
	cout<<"enter ? to exit"<<endl;
	cout<<"enter the string"<<endl;
	cin>>ch;
	while(ch!='?')
	{
		str[i++]=ch;
		cin>>ch;
	}

	i=0;
	cout<<"enter the pattern"<<endl;
	cin>>ch;
	while(ch!='?')
	{
		pattern[i++]=ch;
		cin>>ch;
	}

	ob.SmallestWindow(str,pattern);
}
