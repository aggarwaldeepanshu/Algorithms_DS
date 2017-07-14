#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		int EditDistance(char [],char []);
};

int String::EditDistance(char str1[],char str2[])
{
	int i,j,n,m,count=0;
	n=strlen(str1);
	m=strlen(str2);

	if((n>m+1)||(m>n+1))
		return 0;

	i=0;
	j=0;
	while(i<n && j<m)
	{
		if(count>1)
			return 0;

		if(str1[i]==str2[j])
		{
			i++;
			j++;
		}

		else
		{
			count++;
			if(n==m)
			{
				i++;
				j++;
			}

			else if(n>m)
				i++;

			else
				j++;

		}

	}
	if(count==0)
		return 0;

	return 1;
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

	if(ob.EditDistance(str1,str2))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
