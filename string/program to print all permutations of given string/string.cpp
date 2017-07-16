#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		void permutations(char [],int,int);
};

void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void String::permutations(char str[],int l,int h)
{
	int i;

	if(l==h)
	{
		for(i=0;i<=h;i++)
			cout<<str[i];

		cout<<endl;
	}

	else
	{
		for(i=l;i<=h;i++)
		{
			swap(&str[l],&str[i]);
			permutations(str,l+1,h);
			swap(&str[l],&str[i]);
		}
	}

}

int main(void)
{
	String ob;
	int n;
	char str[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);

	n=strlen(str);

	ob.permutations(str,0,n-1);
}
