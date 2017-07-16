#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		int CheckRotation(char [],char []);
};

int String::CheckRotation(char str1[],char str2[])
{
	int i,j,n,m;
	n=strlen(str1);
	m=strlen(str2);
	if(n!=m)
		return 0;

	char *arr=new char [n];
	arr[0]='\0';

	strcat(arr,str1);
	strcat(arr,str1);

	char *ptr=strstr(arr,str2);

	if(ptr==NULL)
		return 0;
	else
		return 1;
}

int main(void)
{
	String ob;
	int n;
	char str1[max1],str2[max1];

	cout<<"enter the string 1"<<endl;
	cin.get(str1,max1);

	cin.ignore(numeric_limits <streamsize>::max(),'\n');

	cout<<"enter the string 2"<<endl;
	cin.get(str2,max1);

	if(ob.CheckRotation(str1,str2))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
