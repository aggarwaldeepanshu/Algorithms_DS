#include<bits/stdc++.h>
#define max1 500
using namespace std;

class String
{
	public:
		int CheckStringConstruction(char []);
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

int String::CheckStringConstruction(char text[])
{
	int i,j,n,m;
	n=strlen(text);

	int lps[n];
	createLPS(text,lps,n);

	m=lps[n-1];
	if(m>0 && n%(n-m)==0)
		return 1;
	else
		return 0;
}

int main(void)
{
	String ob;

	char text[max1],pat[max1];
	cin.get(text,max1);

	if(ob.CheckStringConstruction(text))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
