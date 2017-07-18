#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void TransformString(char [],char []);
};

void String::TransformString(char str1[],char str2[])
{
	int i,j,n,m,count=0;
	n=strlen(str1);
	m=strlen(str2);
	int hash[max1]={0};
	if(n!=m)
	{
		cout<<"not possible"<<endl;
		return ;
	}

	for(i=0;i<m;i++)
		hash[str1[i]]++;

	for(i=0;i<n;i++)
	{
		if(hash[str2[i]]==0)
		{
			cout<<"not possible"<<endl;
			return ;
		}
	}

	i=n-1;
	j=m-1;
	while(i>=0)
	{
		if(i>=0 && str1[i]==str2[j])
		{
			i--;
			j--;
		}

		else if(i>=0 && str1[i]!=str2[j])
		{
			while(i>=0 && str1[i]!=str2[j])
			{
				count++;
				i--;
			}
		}

	}
	cout<<"minimum number of moves required is "<<count<<endl;
}

int main(void)
{
	int i;
	String ob;
	char str1[max1],str2[max1];
	cout<<"enter the string 1"<<endl;
	cin.get(str1,max1);

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout<<"enter the string 2"<<endl;
	cin.get(str2,max1);

	ob.TransformString(str1,str2);
}
