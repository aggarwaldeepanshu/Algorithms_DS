#include<bits/stdc++.h>
using namespace std;

class DP
{
private:
int n,sum;
int *set;

public:
DP(int,int);
bool find_set();
};

DP::DP(int a,int b)
{
n=a;
sum=b;
set=new int [n];

cout<<"Enter the set values"<<endl;
for(int j=0;j<n;j++)
cin>>set[j];
}

bool DP::find_set()
{
int i,j;
bool **subset=new bool* [n+1];

for(i=0;i<=n;i++)
subset[i]=new bool [n+1];

for(i=0;i<=n;i++)
subset[i][0]=true;

for(i=1;i<=sum;i++)
subset[0][i]=false;

for(i=1;i<=n;i++)
{
for(j=1;j<=sum;j++)
{
if(j<set[i-1])
subset[i][j]=subset[i-1][j];

if(j>=set[i-1])
{
subset[i][j]=subset[i-1][j] || subset[i][j-set[i-1]];
}
}

}
return subset[n][sum];
}


int main(void)
{
int sum,n;
cout<<"enter the size and sum"<<endl;
cin>>n>>sum;

DP ob(n,sum);
if(ob.find_set())
cout<<"true"<<endl;
else
cout<<"false"<<endl;
}
