#include<bits/stdc++.h>
#define max 256
using namespace std;

int main(void)
{
	String ob;
	int i,n;
	cout<<"enter the size"<<endl;
	cin>>n;
	string str[n];

	cout<<"enter the string"<<endl;
	for(i=0;i<n;i++)
		cin>>str[i];

	sort(str,str+n);

	for(i=0;i<n;i++)
		cout<<str[i]<<endl;
}
