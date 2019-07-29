#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		void ShortestPath(char []);
};

void String::ShortestPath(char str[])
{
	int i,n,r1=0,r2,c1=0,c2;
	n=strlen(str);

	for(i=0;i<n;i++)
	{
		r2=(str[i]-'A')/5;
		c2=(str[i]-'A')%5;

		if(r2>r1)
		{
			while(r2>r1)
			{
				cout<<"Move Down"<<endl;
				r1++;
			}
		}

		if(r2<r1)
		{
			while(r2<r1)
			{
				cout<<"Move Up"<<endl;
				r1--;
			}

		}

		if(c2>c1)
		{
			while(c2>c1)
			{
				cout<<"Move Right"<<endl;
				c1++;
			}

		}

		if(c2<c1)
		{
			while(c2<c1)
			{
				cout<<"Move Left"<<endl;
				c1--;
			}
		}

		cout<<"Press OK"<<endl;
	}

}

int main(void)
{
	String ob;
	char str[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);

	ob.ShortestPath(str);

}
