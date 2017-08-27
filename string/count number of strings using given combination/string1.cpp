#include<bits/stdc++.h>
#define max 100
using namespace std;

class String
{
	public:
		int findCombination(int,int ,int,int);
};

int String::findCombination(int n,int r,int g,int b)
{
	int i,j,k,diff,sum=0;

	int fact[n+1];
	fact[0]=1;

	for(i=1;i<=n;i++)
		fact[i]=fact[i-1]*i;

	diff=n-(r+g+b);

	for(i=0;i<=diff;i++)
	{
		for(j=0;j<=diff-i;j++)
		{
			k=diff-(i+j);

			sum+=fact[n]/(fact[i+r]*fact[j+b]*fact[k+g]);
		}

	}
	return sum;
}

int main(void)
{
	int n,r,g,b;
	String ob;

	cout<<"enter n,r,g,b in respective order"<<endl;
	cin>>n>>r>>g>>b;

	int sum=ob.findCombination(n,r,g,b);
	cout<<sum<<endl;
}
