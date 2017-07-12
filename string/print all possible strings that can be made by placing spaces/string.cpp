#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		void AddSpace(char []);
};

void PrintWords(char arr[],char ans[],int i,int j,int n)
{
	int v;
	if(i==n)
	{
		ans[j]='\0';

		cout<<ans<<endl;

		return ;
	}
	ans[j]=arr[i];
	PrintWords(arr,ans,i+1,j+1,n);
	ans[j]=' ';
	ans[j+1]=arr[i];
	PrintWords(arr,ans,i+1,j+2,n);
}

void String::AddSpace(char arr[])
{
	char ans[max];
	char ch;
	int n=strlen(arr);
	ch=arr[n-1];
	ans[0]=arr[0];
	PrintWords(arr,ans,1,1,n);
}

int main(void)
{
	String ob;
	int i,n,num;
	char arr[max];
	cin.get(arr,max);

	ob.AddSpace(arr);
}
