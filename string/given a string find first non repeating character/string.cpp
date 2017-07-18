#include<bits/stdc++.h>
#define max 256
using namespace std;

struct element
{
	int number;
	int pos;
};

class String
{
	public:
		char nonRepeating(char []);
};

char String::nonRepeating(char str[])
{
	int i,n,pos;
	struct element hash[max]={0};
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		if(hash[str[i]].number==0)
		{
			hash[str[i]].number=1;
			hash[str[i]].pos=i;
		}
		else
			hash[str[i]].number++;
	}

	for(i=0;i<max;i++)
	{
		if(hash[i].number==1)
		{
			pos=hash[i].pos;
			return pos;
		}
	}
	return -1;
}

int main(void)
{
	String ob;
	int i;
	char str[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);

	i=ob.nonRepeating(str);
	if(i==-1)
		cout<<"no repeating character"<<endl;
	else
		cout<<str[i]<<endl;
}
