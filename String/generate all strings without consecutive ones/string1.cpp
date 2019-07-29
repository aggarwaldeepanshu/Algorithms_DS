#include<bits/stdc++.h>
#define max 100
using namespace std;

class String
{
	public:
		void generateStrings(int);
};

void printStrings(char str[],int i,int k)
{
	if(i==k)
	{
		cout<<str<<" ";
		return ;
	}

	if(str[i-1]=='0')
	{
		str[i]='0';
		printStrings(str,i+1,k);

		str[i]='1';
		printStrings(str,i+1,k);
	}

	if(str[i-1]=='1')
	{
		str[i]='0';
		printStrings(str,i+1,k);
	}

}

void String::generateStrings(int k)
{
	char str[max];

	str[0]='0';

	printStrings(str,1,k);

	str[0]='1';

	printStrings(str,1,k);
}

int main(void)
{
	int i,k;
	String ob;
	cout<<"enter k"<<endl;
	cin>>k;

	ob.generateStrings(k);
}
