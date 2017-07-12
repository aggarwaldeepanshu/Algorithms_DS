#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		int findMaxDepth(char [],int);
};

int String::findMaxDepth(char str[],int d)
{
	int i,j,n,count=0,val=0;
	n=strlen(str);
	int hash[max];

	for(i=0;i<n;i++)
		hash[str[i]]=0;

	for(i=0;i<n;i++)
	{
		if(hash[str[i]]==0)
		{
			if(count<d)
			{
				hash[str[i]]=1;
				count++;
			}

			else
			{
				hash[str[i]]=2;
				val++;
			}
		}
		else if(hash[str[i]]==1)
		{
			hash[str[i]]=0;
			count--;
		}
		else if(hash[str[i]]==2)
		{
			if(count<d)
			{
				hash[str[i]]=1;
				count++;
			}

		}

	}
	return val;
}

int main(void)
{
	String ob;
	int d;
	char text[max];
	cout<<"enter string"<<endl;
	cin.get(text,max);

	cout<<"number of computers"<<endl;
	cin>>d;

	int count=ob.findMaxDepth(text,d);
	cout<<count<<endl;
}
