#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		int printSequence(char []);
};

int smallestSequence(char str[],int n,int i,int j)
{
	int k;
	for(k=0;k<n;k++)
	{
		if(str[i]>str[j])
			return 1;

		if(str[i]<str[j])
			return 0;

		i=(i+1)%n;
		j=(j+1)%n;
	}

}

int String::printSequence(char str[])
{
	int i,n,index=0;
	n=strlen(str);

	for(i=1;i<n;i++)
	{
		if(smallestSequence(str,n,index,i))
			index=i;

	}
	return index;
}

int main(void)
{
	int i,count=0,n;
	String ob;
	char str[max1];

	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	int index=ob.printSequence(str);
	n=strlen(str);

	for(i=index;count<n;i=(i+1)%n)
	{
		cout<<str[i];
		count++;
	}
}
