#include<iostream>
using namespace std;

class peak{
private:
 int size;
 int *arr;

public:

peak(int n=4){
 size=n;
 arr=new int[size];
}
void get(){
 cout<<"Enter the array size"<<endl;
 cin>>size;
 arr=new int[size];
 cout<<"Enter the values"<<endl;
 for(int i=0;i<size;i++)
 cin>>arr[i];
}
void peak_element();

~peak(){
delete [] arr;
}
};

int binary_search(int arr[],int low,int high){
int mid;
if(low==high)
return low;

if(low<high){
mid=(low+high)/2;
  if(mid==low&&arr[mid]>=arr[mid+1])
   return mid;
  else if(mid==high&&arr[mid]>=arr[mid-1])
   return mid;
  else if(mid-1>low&&mid+1<high&&arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
    return mid;
  else if(mid-1>=low&&arr[mid]<arr[mid-1])
    return binary_search(arr,low,mid-1);
  else
    return binary_search(arr,mid+1,high);
}
}

void peak::peak_element(){
 int val;
 val=binary_search(arr,0,size-1);
 cout<<"The required peak element is "<<arr[val]<<endl;
}

int main(void){
 peak ob;
 ob.get();
 ob.peak_element();
}
