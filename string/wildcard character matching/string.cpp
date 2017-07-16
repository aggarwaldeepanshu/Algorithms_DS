#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		int stringMatching(char [],char[],int,int);
};

int String::stringMatching(char str1[],char str2[],int i,int j)
{
	if(str1[i]=='\0' && str2[j]=='\0')
		return 1;

	if(str1[i]=='*' && str1[i+1]!='\0' && str2[j]=='\0')
		return 0;

	if(str1[i]=='?' || str1[i]==str2[j])
		return stringMatching(str1,str2,i+1,j+1);

	if(str1[i]=='*')
		return (stringMatching(str1,str2,i+1,j)||stringMatching(str1,str2,i,j+1));
	return 0;
}

int main(void)
{
	String ob;
	int n,m,i;
	char str1[max1],str2[max1];

	cout<<"enter the string with wildcard characters"<<endl;
	cin.get(str1,max1);

	cin.ignore(numeric_limits <streamsize>::max(),'\n');

	cout<<"enter the normal string"<<endl;
	cin.get(str2,max1);

	if(ob.stringMatching(str1,str2,0,0))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
