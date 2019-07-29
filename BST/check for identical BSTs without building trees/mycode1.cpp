#include<bits/stdc++.h>
using namespace std;

class BST
{
	public:
		int CheckIdentical(int [],int [],int);
};

int CheckIdenticalRecur(int arr1[],int arr2[],int i,int j,int n,int min,int max)
{
	int k,l;
	for(k=i;k<n;k++)
		if(arr1[k] > min && arr1[k] < max)
			break;

	for(l=j;l<n;l++)
		if(arr2[l] > min && arr2[l] < max)
			break;

	if(l==n && k==n)
		return 1;

	if(l==n ^ k==n || arr1[k]!=arr2[l])
		return 0;

	return (CheckIdenticalRecur(arr1,arr2,k+1,l+1,n,arr1[k],max) && CheckIdenticalRecur(arr1,arr2,k+1,l+1,n,min,arr1[k]));
}

int BST::CheckIdentical(int arr1[],int arr2[],int n)
{
	return CheckIdenticalRecur(arr1,arr2,0,0,n,INT_MIN,INT_MAX);
}

int main(void)
{
	BST ob;
	int i,n;
	cout<<"enter the size"<<endl;
	cin>>n;

	int arr1[n],arr2[n];
	cout<<"enter values for first array"<<endl;
	for(i=0;i<n;i++)
		cin>>arr1[i];

	cout<<"enter values for second array"<<endl;
	for(i=0;i<n;i++)
		cin>>arr2[i];

	if(ob.CheckIdentical(arr1,arr2,n))
		cout<<"identical"<<endl;
	else
		cout<<"not identical"<<endl;
}
