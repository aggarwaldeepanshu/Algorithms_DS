#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void reverseString(char []);
};

int isvalid(char ch)
{
	if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z'))
		return 1;
	else
		return 0;
}

void String::reverseString(char str[])
{
	int i,j,n;
	char temp;
	n=strlen(str);
	i=0;
	j=n-1;
	while(i<j)
	{
		if(isvalid(str[i]) && isvalid(str[j]))
		{
			temp=str[i];
			str[i]=str[j];
			str[j]=temp;
			i++;
			j--;
		}

		else if(isvalid(str[i]))
			j--;

		else
			i++;
	}
	return ;
}

int main(void)
{
	int i;
	String ob;
	char str[max1];

	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	cout<<"before reversal"<<endl<<str<<endl;

	ob.reverseString(str);

	cout<<"after reversal"<<endl<<str<<endl;
}
