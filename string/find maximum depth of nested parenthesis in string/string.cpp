#include<bits/stdc++.h>
#define max1 500
using namespace std;

class String
{
	public:
		int findMaxDepth(char []);
};

int String::findMaxDepth(char str[])
{
	int i,n,max=-1,count=0;
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		if(str[i]=='(')
			count++;

		else if(str[i]==')')
		{
			if(count==0)
				return -1;

			count--;
		}

		if(count>max)
			max=count;

	}
	if(count!=0)
		return -1;

	return max;
}

int main(void)
{
	String ob;

	char text[max1],pat[max1];
	cin.get(text,max1);

	int count=ob.findMaxDepth(text);
	cout<<count<<endl;
}
