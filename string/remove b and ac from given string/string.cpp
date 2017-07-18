#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void RemoveCharacters(char []);
};

void String::RemoveCharacters(char str[])
{
	int i,j=0,n;
	bool flag=false;
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		if(flag==false && str[i]!='b' && str[i]!='a')
			str[j++]=str[i];

		if(flag==true && str[i]!='b' && str[i]!='a')
			str[j++]=str[i];

		if(str[i]=='a')
		{
			str[j++]=str[i];
			flag=true;
		}

		else
			flag=false;

		if(j>1 && str[j-2]=='a' && str[j-1]=='c')
			j-=2;
	}

	for(i=0;i<j;i++)
		cout<<str[i];

	cout<<endl;
}

int main(void)
{
	String ob;
	int n,m,i;
	char str[max1];

	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	ob.RemoveCharacters(str);
}
