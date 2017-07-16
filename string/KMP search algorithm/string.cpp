#include<bits/stdc++.h>
#define max1 500
using namespace std;

class String
{
	public:
		void KMPsearch(char [],char []);
};

void createLPS(char pat[],int lps[],int size)
{
	int i=1,j=0;
	lps[0]=0;
	while(i<size)
	{
		if(pat[i]==pat[j])
		{
			lps[i]=1+j;
			j++;
			i++;
		}
		else
		{
			if(j==0)
			{
				lps[i]=0;
				i++;
			}

			else
			{
				j=lps[j-1];
			}
		}

	}

}

void String::KMPsearch(char text[],char pat[])
{
	int i,j,n,m;
	n=strlen(text);
	m=strlen(pat);
	int lps[m];
	createLPS(pat,lps,m);
	i=0;
	j=0;
	while(i<n)
	{
		if(text[i]==pat[j])
		{
			i++;
			j++;
		}

		if(j==m)
		{
			cout<<"pattern found at index "<<i-m<<endl;
			j=lps[m-1];
		}

		else if(j<m && text[i]!=pat[j])
		{
			if(j==0)
				i++;

			else
			{
				j=lps[j-1];
			}
		}

	}
}

int main(void)
{
	String ob;

	char text[max1],pat[max1];
	cin.get(text,max1);

	cin.ignore(numeric_limits <streamsize>::max(),'\n');

	cin.get(pat,max1);
	ob.KMPsearch(text,pat);
}
