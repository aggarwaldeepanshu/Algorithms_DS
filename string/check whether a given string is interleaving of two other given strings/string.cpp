#include<iostream>
#include<cstring>
#define max 50
using namespace std;

class String
{
	public:
		int CheckInterleaving(char [],char[],char []);
};

int CheckRecur(char str1[],char str2[],char str[],int n1,int n2,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(n1>0 && str1[0]==str[i])
		{
			str1=str1+1;
			n1--;
		}

		else if(n2>0 && str2[0]==str[i])
		{
			str2=str2+1;
			n2--;
		}

		else
			return 0;
	}

	if(n1||n2)
		return 0;

	return 1;
}

int String::CheckInterleaving(char str1[],char str2[],char str[])
{
	int i,n1,n2,n3;
	n1=strlen(str1);
	n2=strlen(str2);
	n3=strlen(str);

	return CheckRecur(str1,str2,str,n1,n2,n3);
}

int main(void)
{
	String ob;
	int i=0;
	char str1[max],str2[max],str[max],ch;
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

	i=0;
	cout<<"enter the string to compare"<<endl;
	cin>>ch;
	while(ch!='?')
	{
		str[i++]=ch;
		cin>>ch;
	}

	if(ob.CheckInterleaving(str1,str2,str))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
