#include<bits/stdc++.h>
#define max 256
using namespace std;

class String
{
	public:
		void Rearrange(char [],char [],int);
};

int findMax(int freq[],int dist[])
{
	int i,max1;
	max1=INT_MIN;
	for(i=0;i<max;i++)
	{
		if(dist[i]<=0 && freq[i]>0 && (max1==INT_MIN || freq[i]>freq[max1]))
			max1=i;
	}
	return max1;
}

void String::Rearrange(char str[],char ans[],int d)
{
	int i,j,n,index;
	n=strlen(str);
	int freq[max]={0};
	int dist[max]={0};

	for(i=0;i<n;i++)
		freq[str[i]]++;

	for(i=0;i<n;i++)
	{
		index=findMax(freq,dist);

		if(index==INT_MIN)
			return ;

		ans[i]=index;

		freq[index]--;

		dist[index]=d;

		for(j=0;j<max;j++)
			dist[j]--;
	}

	ans[n]='\0';

}

int main(void)
{
	String ob;
	int n,m,i,d;
	char str[max],ans[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);

	cout<<"enter d"<<endl;
	cin>>d;

	ob.Rearrange(str,ans,d);
	cout<<"after rearranging"<<endl<<ans<<endl;

}
