#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void printString(char []);
};

void String::printString(char str[])
{
	int i,j,n,k;
	n=strlen(str);
	for(i=0,j=n-1;i<n,j>=0;i++,j--)
	{
		if(i<j)
		{
			for(k=0;k<i;k++)
				cout<<" ";

			cout<<str[i];

			for(k=0;k<j-i-1;k++)
				cout<<" ";

			cout<<str[j];
		}

		else if(i==j)
		{
			for(k=0;k<i;k++)
				cout<<" ";

			cout<<str[i];
		}

		else if(i>j)
		{
			for(k=0;k<j;k++)
				cout<<" ";

			cout<<str[j];

			for(k=0;k<i-j-1;k++)
				cout<<" ";

			cout<<str[i];
		}

	cout<<endl;
	}
}

int main(void)
{
	int i;
	String ob;
	char str[max1];
	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	ob.printString(str);
}
