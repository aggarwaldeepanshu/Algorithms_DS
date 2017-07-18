#include<bits/stdc++.h>
#define max 100
using namespace std;

class String
{
	public:
		void ReverseWords(char []);
};

void reverse(char str[],int size)
{
	int i,j;
	char temp;

	i=0;
	j=size-1;
	while(i<j)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
}

void String::ReverseWords(char str[])
{
	int i,j=0,n,count=0;
	n=strlen(str);
	str[n]='\0';
	for(i=0;i<=n;i++)
	{
		if(str[i]==char(32))
		{
			reverse(str+j,count-j);
			j=i+1;
			count++;
		}
		else if(str[i]=='\0')
		{
			reverse(str+j,count-j);
		}
		else
			count++;

	}
	reverse(str,n);
	for(i=0;i<n;i++)
		cout<<str[i];
}

int main(void)
{
	String ob;
	int i=0;
	char str[max],ch;

	cout<<"enter the string"<<endl;

	cin.get(str,max);

	for(i=0;i<strlen(str);i++)
		cout<<str[i];

	cout<<endl;
	ob.ReverseWords(str);
}
