#include<bits/stdc++.h>
#define max 100
using namespace std;

class String
{
	public:
		void findSum(char []);
};

void String::findSum(char str[])
{
	int sum=0,num=1;

	for(int i=strlen(str)-1;i>=0;i--)
	{
		sum+=(str[i]-'0')*num*(i+1);

		num=num*10+1;
	}

	cout<<"sum is "<<sum<<endl;
}

int main(void)
{
	int i;
	String ob;

	char str[max];
	cin.get(str,max);

	ob.findSum(str);
}
