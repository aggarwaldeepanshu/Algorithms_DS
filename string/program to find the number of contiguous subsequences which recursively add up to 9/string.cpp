#include<bits/stdc++.h>
#define max1 256
using namespace std;

class String
{
	public:
		int count_to_9(char []);
};

int String::count_to_9(char str[])
{
	int i,sum=0,continuous_zero=0,count=0,n,ans=0;
	int arr[10];
	n=strlen(str);
	memset(arr,0,sizeof(arr));
	arr[0]=1;

	for(i=0;i<n;i++)
	{
		if(!(str[i]-'0'))
			continuous_zero++;

		else
			continuous_zero=0;

		sum+=(str[i]-'0');
		sum%=9;
		ans+=arr[sum];
		arr[sum]++;

		ans-=continuous_zero;
	}

	return ans;
}

int main(void)
{
	int i,r;
	String ob;
	char str[max1];

	cout<<"enter the string"<<endl;
	cin.get(str,max1);

	int ans=ob.count_to_9(str);
	cout<<ans<<endl;
}
