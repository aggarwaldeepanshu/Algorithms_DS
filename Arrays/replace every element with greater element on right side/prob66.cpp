#include<iostream>
using namespace std;

int find(int max,int temp){
return (max>temp)?max:temp;
}

int main(void){
int i,n,temp,max;
cout<<"Array size"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the array elements"<<endl;
for(i=0;i<n;i++)
cin>>arr[i];
max=arr[n-1];
arr[n-1]=-1;
for(i=n-2;i>=0;i--){
temp=arr[i];
arr[i]=max;
max=find(max,temp);
}
for(i=0;i<n;i++)
cout<<arr[i]<<" "<<endl;
}
