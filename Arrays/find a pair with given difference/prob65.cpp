#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
int i,n,j,val,v=0;
cout<<"Enter the size of array"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the values"<<endl;
for(i=0;i<n;i++)
cin>>arr[i];
cout<<"Enter the difference"<<endl;
cin>>val;
sort(arr,arr+n);
i=0;
j=1;
while(i<n&&j<n){
if(arr[j]-arr[i]==val){
v=1;
break;
}
else if(arr[j]-arr[i]>val)
i++;
else
j++;
}
if(v==1)
cout<<arr[i]<<","<<arr[j]<<endl;
else
cout<<"No such pair"<<endl;
}
