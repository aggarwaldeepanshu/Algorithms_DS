#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void AddStrings(char [],char []);
};

void reverse(char str[])
{
	int i,j,n;
	char temp;
	n=strlen(str);
	i=0;
	j=n-1;
	while(i<j)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
	return ;
}

void String::AddStrings(char str1[],char str2[])
{
	int i,j,n,m,sum=0,carry=0,k=0;
	n=strlen(str1);
	m=strlen(str2);
	char str[max1];
	i=n-1;
	j=m-1;
	while(i>=0 && j>=0)
	{
		sum=(str1[i]-'0')+(str2[j]-'0')+carry;
		carry=sum/2;
		sum=sum%2;
		str[k++]=sum+'0';
		i--;
		j--;
	}

	if(i==-1 && j==-1)
	{
		str[k]=carry+'0';
	}

	else if(i==-1)
	{
		while(j>=0)
		{
			sum=(str2[j]-'0')+carry;
			carry=sum/2;
			sum=sum%2;
			str[k++]=sum+'0';
			j--;
		}

		str[k]=carry+'0';
	}

	else if(j==-1)
	{
		while(i>=0)
		{
			sum=(str1[i]-'0')+carry;
			carry=sum/2;
			sum=sum%2;
			str[k++]=sum+'0';
			i--;
		}

		str[k]=carry+'0';
	}

	reverse(str);
	cout<<"string after adding is"<<endl;
	cout<<str<<endl;
}

int main(void)
{
	int i;
	String ob;
	char str1[max1],str2[max1];
	cout<<"enter the string 1"<<endl;
	cin.get(str1,max1);

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout<<"enter the string 2"<<endl;
	cin.get(str2,max1);

	ob.AddStrings(str1,str2);
}
