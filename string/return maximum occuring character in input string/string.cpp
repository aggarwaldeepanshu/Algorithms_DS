#include<iostream>
#include<string>
#define max 45
using namespace std;

class String
{
	public:
		char findMaximum(string );
};

char String::findMaximum(string str)
{
	int arr[max],i,len,maximum=0,j;

	for(i=0;i<30;i++)
		arr[i]=0;

	len=str.length();
	for(i=0;i<len;i++)
		arr[str[i]-'a']++;

	for(i=0;i<30;i++)
	{
		if(arr[i]>maximum)
		{
			j=i;
			maximum=arr[i];
		}
	}
	return j+'a';
}

int main(void)
{
	String ob;
	string str;
	char ch;
	cout<<"enter the string"<<endl;
	cin>>str;
	ch=ob.findMaximum(str);
	cout<<"character occuring maximum times is "<<ch<<endl;
}
