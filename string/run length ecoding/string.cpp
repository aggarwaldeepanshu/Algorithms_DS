#include<bits/stdc++.h>
#define max 50
using namespace std;

class String
{
	public:
		string encode(char []);
};

string String::encode(char str[])
{
	int i,n,k,j,count;
	n=strlen(str);
	string str1;

	for(i=0;i<n;i++)
	{
		str1+=str[i];
		count=1;
		while(i<n && str[i]==str[i+1])
		{
			count++;
			i++;
		}
		str1+=count+'0';
	}
	return str1;
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

	string str1=ob.encode(str);
	cout<<str1<<endl;
}
