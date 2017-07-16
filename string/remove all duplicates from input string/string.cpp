#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		void RemoveCharacters(char []);
};

void String::RemoveCharacters(char str[])
{
	int i,j=0,n;
	n=strlen(str);
	int hash[max]={0};

	for(i=0;i<n;i++)
	{
		if(hash[str[i]]==0)
		{
			hash[str[i]]++;
			str[j++]=str[i];
		}
	}

	for(i=0;i<j;i++)
		cout<<str[i];
}

int main(void)
{
	String ob;
	int n,i;
	char str[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);

	ob.RemoveCharacters(str);
}
