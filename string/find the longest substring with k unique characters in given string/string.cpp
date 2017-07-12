#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		void findLongestSubstring(char [],int);
};

int checkCount(int hash[],int k)
{
	int val=0;
	for(int i=0;i<max1;i++)
		if(hash[i]>0)
			val++;

	if(val<=k)
		return 0;
	else
		return 1;
}

void String::findLongestSubstring(char str[],int k)
{
	int i,n,start=0,end=0,u=0,max=-1,max_start=0;
	n=strlen(str);
	int hash[max1]={0};
	for(i=0;i<n;i++)
	{
		if(hash[str[i]]==0)
			u++;

		hash[str[i]]++;
	}

	if(u<k)
	{
		cout<<"not possible"<<endl;
		return ;
	}

	memset(hash,0,sizeof(hash));

	for(i=0;i<n;i++)
	{
		hash[str[i]]++;
		end++;

		while(checkCount(hash,k))
		{
			hash[str[start]]--;
			start++;
		}

		if(end-start+1>max)
		{
			max=end-start+1;
			max_start=start;
		}

	}

	for(i=max_start;max>0;i++)
	{
		cout<<str[i];
		max--;
	}

}

int main(void)
{
	String ob;
	int k;
	char text[max1];
	cout<<"enter string"<<endl;
	cin.get(text,max1);

	cout<<"enter k"<<endl;
	cin>>k;

	ob.findLongestSubstring(text,k);
}
