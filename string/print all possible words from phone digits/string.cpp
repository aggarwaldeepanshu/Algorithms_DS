#include<bits/stdc++.h>
#define max 256
using namespace std;

char str[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class String
{
	public:
		void findWords(int [],int);
};

void PrintWords(int arr[],char ans[],int index,int n)
{
	int i;
	if(index==n)
	{
		for(i=0;i<n;i++)
			cout<<ans[i];

		cout<<" ";
		return ;
	}

	for(i=0;i<strlen(str[arr[index]]);i++)
	{
		ans[index]=str[arr[index]][i];
		PrintWords(arr,ans,index+1,n);
		if(arr[index]==0 || arr[index]==1)
			return ;
	}

}

void String::findWords(int arr[],int n)
{
	char ans[n];
	ans[n]='\0';
	PrintWords(arr,ans,0,n);
}

int main(void)
{
	String ob;
	int i,n,num;
	cout<<"enter the length of number"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the digits"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>num;
		arr[i]=num;
	}

	ob.findWords(arr,n);
}
