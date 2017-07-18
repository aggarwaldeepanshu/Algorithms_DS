#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void splitstring(char []);
};

void String::splitstring(char str[])
{
	int i;
	char *arr=strtok(str,"-");
	while(arr!=NULL)
	{
		cout<<arr<<endl;
		arr=strtok(NULL,"-");
	}

}

int main(void)
{
	int i,r;
	String ob;
	char str[max1];

	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	ob.splitstring(str);
}
