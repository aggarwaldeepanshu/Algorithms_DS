#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		int findColumn(int);
};

string ReverseString(string str)
{
	int i=0,j;
	char temp;
	j=str.length()-1;

	while(i<j)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}

	return str;
}

int String::findColumn(int num)
{
	int i;
	string str;
	while(num>0)
	{
		i=num%26;
		if(i==0)
		{
			str+='Z';
			num=num/26-1;
		}

		else
		{
			str+=i+'A'-1;
			num=num/26;
		}

	}

	str=ReverseString(str);
	cout<<str<<endl;
}

int main(void)
{
	String ob;
	int i,n;
	cout<<"enter number"<<endl;
	cin>>n;
	ob.findColumn(n);
}
