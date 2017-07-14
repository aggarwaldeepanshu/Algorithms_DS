#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void RemoveRecuringDigits(char []);
};

void String::RemoveRecuringDigits(char str[])
{
	int i,j,n;
	n=strlen(str);
	i=1;
	j=0;
	while(i<n)
	{
		if(str[i]==str[j])
			i++;

		else
		{
			j++;
			str[j]=str[i];
			i++;
		}

	}
	str[++j]='\0';
}

int main(void)
{
	int i;
	String ob;
	char str[max1];

	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	cout<<"before removing"<<endl<<str<<endl;

	ob.RemoveRecuringDigits(str);

	cout<<"after removing"<<endl<<str<<endl;
}
