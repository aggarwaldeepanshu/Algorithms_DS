#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		void stringReverse(char [],int,int);
};

void String::stringReverse(char str[],int l,int h)
{
	if(l==h)
	{
		cout<<str[l];
		return ;
	}

	stringReverse(str,l+1,h);
	cout<<str[l];
}

int main(void)
{
	String ob;
	int n;
	char str[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);

	n=strlen(str);

	ob.stringReverse(str,0,n-1);
}
