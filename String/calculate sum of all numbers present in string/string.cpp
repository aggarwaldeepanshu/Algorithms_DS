#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		void findSum(char []);
};

void String::findSum(char str[])
{
	int temp=0,i=0,n,sum=0;
	n=strlen(str);

	while(i<n)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			while(i<n && str[i]>='0' && str[i]<='9')
			{
				temp=temp*10+(str[i]-'0');
				i++;
			}
			sum+=temp;
			temp=0;
		}

		if(i<n && (str[i]<'0' || str[i]>'9'))
			i++;

	}
	cout<<sum<<endl;
}

int main(void)
{
	String ob;
	char str[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);

	ob.findSum(str);

}
