#include<iostream>
using namespace std;

class interchange
{
private:
int size;
int *arr;

public:

interchange(int n=4)
{
size=n;
arr=new int[size];
}
void get()
{
cout<<"Enter the array size"<<endl;
cin>>size;
arr=new int[size];
cout<<"Enter the values"<<endl;
for(int i=0;i<size;i++)
cin>>arr[i];
}
void rearrange();
void display()
{
cout<<"The required array is:"<<endl;
for(int i=0;i<size;i++)
cout<<arr[i]<<" ";
}
};

void interchange::rearrange()
{
int i,k,val,j;
for(i=0;i<size;i++)
arr[i]++;

for(i=0;i<size;i++)
{
if(arr[i]>0)
{
j=i;
val=-(j+1);
j=arr[j]-1;
while(arr[j]>0)
{
k=arr[j]-1;
arr[j]=val;
val=-(j+1);
j=k;
}
}
}

for(i=0;i<size;i++)
arr[i]=(-arr[i])-1;
}

int main(void)
{
interchange ob;
ob.get();
ob.rearrange();
ob.display();
}
