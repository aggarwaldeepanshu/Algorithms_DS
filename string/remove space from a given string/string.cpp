#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		void removeSpace(char str[]);
};

void String::removeSpace(char str[])
{
	int i,j=0,n;
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')
			str[j++]=str[i];
	}
	str[j]='\0';
}

int main(void)
{
	int i;
	String ob;
	char str[max];
	cout<<"enter the string"<<endl;
	cin.get(str,max);

	cout<<"before removing space"<<endl;
	cout<<str<<endl;

	ob.removeSpace(str);

	cout<<"after removing space"<<endl;
	cout<<str<<endl;
}
