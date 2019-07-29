#include<iostream>
#include<cstring>
#define max 50
using namespace std;

class String
{
	public:
		void PrintInterleaving(char [],char[]);
};

void PrintRecur(char str1[],char str2[],char str[],int n1,int n2,int i)
{
	if(n1==0 && n2==0)
	{
		cout<<str<<endl;
		return ;
	}

	if(n1!=0)
	{
		str[i]=str1[0];
		PrintRecur(str1+1,str2,str,n1-1,n2,i+1);
	}

	if(n2!=0)
	{
		str[i]=str2[0];
		PrintRecur(str1,str2+1,str,n1,n2-1,i+1);
	}
	return ;
}

void String::PrintInterleaving(char str1[],char str2[])
{
	int i,n1,n2;
	n1=strlen(str1);
	n2=strlen(str2);
	char str[n1+n2+1];
	str[n1+n2+1]='\0';
	PrintRecur(str1,str2,str,n1,n2,0);
}

int main(void)
{
	String ob;
	int i=0;
	char str1[max],str2[max],ch;
        cout<<"enter ? to exit"<<endl;
	cout<<"enter the string 1"<<endl;
	cin>>ch;
	while(ch!='?')
	{
		str1[i++]=ch;
		cin>>ch;
	}

	i=0;
	cout<<"enter the string 2"<<endl;
	cin>>ch;
	while(ch!='?')
	{
		str2[i++]=ch;
		cin>>ch;
	}

	ob.PrintInterleaving(str1,str2);
}
