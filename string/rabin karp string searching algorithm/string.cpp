#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void RabinKarp(char [],char []);
};

int isMatching(char str[],char pat[],int start,int end)
{
	int i,j=0;
	for(i=start;i<=end;i++)
	{
		if(str[i]!=pat[j])
			return 0;

		j++;
	}
	return 1;
}

int HashFunction(char str[],int start,int end)
{
	int i,hash=0;
	for(i=start;i<=end;i++)
	{
		hash+=(str[i]-96)*pow(101,i);
	}

	return hash;
}

void String::RabinKarp(char str[],char pat[])
{
	int i,n,m,hash,start,end,val;
	n=strlen(str);
	m=strlen(pat);

	hash=HashFunction(pat,0,m-1);

	start=0;
	end=m-1;

	val=HashFunction(str,start,end);

	for(i=1;i<n;i++)
	{
		if(val==hash)
		{
			if(isMatching(str,pat,start,end))
			{
				cout<<"pattern found at index "<<start<<endl;
			}
		}

		if(end==n-1)
			break;

		end++;
		val-=(str[start]-96);
		val/=101;
		val+=(str[end]-96)*pow(101,m-1);
		start++;
	}

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

	ob.RabinKarp(str,pat);
}
