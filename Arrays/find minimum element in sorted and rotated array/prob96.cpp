#include<iostream>
using namespace std;

class pivot{
private:
 int size;
 int *arr;

public:

pivot(int n=4){
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
void find_minimum();
~pivot(){
 delete [] arr;
}
};

int binary_search(int arr[],int low,int high){
 int mid;
 if(low>high)
  return 0;
 if(low==high)
  return low;

  mid=(low+high)/2;
  if(mid>low&&arr[mid]<arr[mid-1]&&arr[mid]<arr[mid+1])
   return mid;
   if(mid<high&&arr[mid]>arr[mid+1])
    return mid+1;
   if(arr[mid]<arr[high])
    return binary_search(arr,low,mid-1);

    return binary_search(arr,mid+1,high);

}

void pivot::find_minimum(){
 int val;
 val=binary_search(arr,0,size-1);
 cout<<"The minimum element is "<<arr[val];
}
int main(void){
pivot ob;
ob.get();
ob.find_minimum();
}
