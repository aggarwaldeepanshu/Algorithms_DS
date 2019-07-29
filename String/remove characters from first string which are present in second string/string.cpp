#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		string RemoveCharacters(char [],char []);
};

string String::RemoveCharacters(char str1[],char str2[])
{
	int n,m,i;
	int hash[max1]={0};
	n=strlen(str1);
	m=strlen(str2);

	string str;

	for(i=0;i<m;i++)
		hash[str2[i]]++;

	for(i=0;i<n;i++)
	{
		if(hash[str1[i]]==0)
			str+=str1[i];

	}
	str+='\0';
	return str;
}

int main(void)
{
	String ob;
	int n;
	char str1[max1],str2[max1];

	cout<<"enter the string"<<endl;
	cin.get(str2,max1);

	cin.ignore(numeric_limits <streamsize>::max(),'\n');

	cout<<"enter the string from which characters to be removed"<<endl;
	cin.get(str1,max1);

	string str=ob.RemoveCharacters(str1,str2);
	cout<<str<<endl;
}
