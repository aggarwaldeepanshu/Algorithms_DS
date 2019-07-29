#include<iostream>
#define size 500
using namespace std;

class search
{
private:
int key;
int *arr;

public:

void get()
{
int i=0,v;
arr=new int[size];
cout<<"Enter the values\nPress -1 to exit"<<endl;
cin>>v;
while(v!=-1)
{
arr[i]=v;
i++;
cin>>v;
}
cout<<"enter the key"<<endl;
cin>>key;
}
void infinite();
};

int binary_search(int arr[],int low,int high,int key)
{
int mid;
if(low<=high)
{
mid=(low+high)/2;
if(arr[mid]==key)
return mid;
else if(arr[mid]>key)
return binary_search(arr,low,mid-1,key);
else
return binary_search(arr,mid+1,high,key);
}
return -1;
}

void search::infinite()
{
int low=0,high=1,val;
while(1)
{
if(arr[high]<key)
{
low=high;
high=high*2;
}
else
{
val=binary_search(arr,low,high,key);
break;
}
}
if(val==-1)
cout<<"Element is not present"<<endl;
else
cout<<"The required index is "<<val<<endl;
}

int main(void)
{
search ob;
ob.get();
ob.infinite();
}
