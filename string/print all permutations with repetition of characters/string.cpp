#include<iostream>
#include<cstring>
#define max 50
using namespace std;

class String
{
	public:
		void PrintPermutation(char []);
};

void PrintRecur(char str[],char str1[],int n,int i)
{
	int j,k;

	for(j=0;j<=n;j++)
	{
		str1[i]=str[j];

		if(i==n)
		{
			for(k=0;k<=n;k++)
				cout<<str1[k];

			cout<<endl;
		}

		else
			PrintRecur(str,str1,n,i+1);

	}
}

void String::PrintPermutation(char str[])
{
	int i,n;
	n=strlen(str);
	char str1[max];
	PrintRecur(str,str1,n-1,0);

	return ;
}

int main(void)
{
	String ob;
	int i=0;
	char str[max],ch;
	cout<<"enter ? to exit"<<endl;
	cout<<"enter the string"<<endl;
	cin>>ch;
	while(ch!='?')
	{
		str[i++]=ch;
		cin>>ch;
	}

	ob.PrintPermutation(str);
}
