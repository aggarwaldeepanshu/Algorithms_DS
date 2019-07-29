#include<iostream>
using namespace std;

class pancake_problem{
private:
 int size;
 int *arr;

public:
 pancake_problem(int n=4){
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
 void sort();

void display(){
cout<<"Array after sorting is"<<endl;
for(int i=0;i<size;i++)
cout<<arr[i]<<" ";
}
};

int binary_search(int arr[],int low,int high,int val){
int mid;
  if(arr[low]>=val)
  return low;

  if(arr[high]<=val)
   return -1;

   mid=(low+high)/2;
   if(arr[mid]==val)
    return mid;
   if(arr[mid]>val){
     if(mid-1>=low&&arr[mid-1]<val)
       return mid;
     else
       return binary_search(arr,low,mid-1,val);
}
    if(arr[mid]<val){
      if(mid+1<=high&&arr[mid+1]>val)
        return mid+1;
      else
        return binary_search(arr,mid+1,high,val);
}
}

void flip(int arr[],int n){
int temp,i=0;
while(i<n){
 temp=arr[i];
 arr[i]=arr[n];
 arr[n]=temp;
 i++;
 n--;
}
}

void pancake_problem::sort(){
int i,j,val,v;
 for(i=1;i<size;i++){
   val=arr[i];
   v= binary_search(arr,0,i-1,val);
   if(v!=-1){
     flip(arr,v-1);
     flip(arr,i-1);
     flip(arr,i);
     flip(arr,v);
}
}
}

int main(void){
pancake_problem ob;
ob.get();
ob.sort();
ob.display();
}
