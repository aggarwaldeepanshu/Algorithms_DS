#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void OnesTwosComplement(char []);
};

void String::OnesTwosComplement(char str[])
{
	int i,n,sum,carry;
	string str1,str2;
	n=strlen(str);

	for(i=0;i<n;i++)
	{
		if(str[i]=='0')
			str1+='1';

		else if(str[i]=='1')
			str1+='0';
	}

	cout<<"1's complement is "<<str1<<endl;
	carry=1;

	for(i=n-1;i>=0;i--)
	{
		sum=(str1[i]-'0')+carry;
		carry=sum/2;
		sum%=2;
		str2+=(sum+'0');
	}
	str2+=carry+'0';
	reverse(str2.begin(),str2.end());
	cout<<"2's complement is "<<str2<<endl;
}

int main(void)
{
	int i,r;
	String ob;
	char str[max1];

	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	ob.OnesTwosComplement(str);
}
