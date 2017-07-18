#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		int WordCount(char []);
};

int String::WordCount(char str[])
{
	int i,count=0,n;
	bool flag=true;
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		if(str[i]==' ' || str[i]=='\n' || str[i]=='\t')
			flag=true;

		else if(flag==true)
		{
			count++;
			flag=false;
		}

	}
	return count;
}

int main(void)
{
	String ob;
	int n,i;
	char str[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);

	int count=ob.WordCount(str);
	cout<<"number of words is "<<count<<endl;
}
