#include<bits/stdc++.h>
#define max1 256
#define up 0
#define down 1
using namespace std;

class String
{
	public:
		void zigzagstring(char [],int);
};

void String::zigzagstring(char str[],int r)
{
	int i=0,j=0,dir,n;
	n=strlen(str);

	string str1[n];
	dir=down;

	for(i=0;i<n;i++)
	{
		str1[j]+=str[i];
		if(j==r-1)
			dir=up;

		if(j==0)
			dir=down;

		if(dir==down)
			j++;

		if(dir==up)
			j--;

	}

	for(i=0;i<n;i++)
		cout<<str1[i];
}

int main(void)
{
	int i,r;
	String ob;
	char str[max1];

	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	cout<<"enter number of rows"<<endl;
	cin>>r;
	//cout<<"before adjustment"<<endl<<str<<endl;

	ob.zigzagstring(str,r);

	//cout<<"after adjustment"<<endl<<str<<endl;
}
