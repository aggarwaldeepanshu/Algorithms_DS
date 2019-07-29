#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		int isPalindrome(string);
};

int String::isPalindrome(string str)
{
	int n,i,j;
	n=str.length();
	i=0;
	j=n-1;
	while(i<j)
	{
		if(str[i]!=str[j])
			return 0;

		i++;
		j--;
	}
}

int main(void)
{
	String ob;
	int i,n;
	string str;

	cout<<"enter the string"<<endl;
	cin>>str;

	if(ob.isPalindrome(str))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
