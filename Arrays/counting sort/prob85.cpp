#include<iostream>
using namespace std;

class counting_sort{
private:
 int size;
 int *arr;

public:

counting_sort(int n=4){
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

void counting_sort::sort(){
 int i;
 int temp[size],output[size];
  for(i=0;i<=size;i++)
   temp[i]=0;
  
  for(i=0;i<size;i++)
  temp[arr[i]]+=1;

  for(i=1;i<=size;i++)
  temp[i]+=temp[i-1];

  for(i=0;i<size;i++){
   output[temp[arr[i]]-1]=arr[i];
   temp[arr[i]]-=1;
}
  for(i=0;i<size;i++)
   arr[i]=output[i];
}

int main(void){
counting_sort ob;
ob.get();
ob.sort();
ob.display();
}
