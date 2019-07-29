#include<iostream>
using namespace std;

class repeating_number{
private:
 int size;
 int *arr;
 int k;

public:
repeating_number(int n=4,int v=4){
 size=n;
 arr=new int[size];
 k=v;
}
void get(){
 cout<<"Enter the array size"<<endl;
 cin>>size;
 arr=new int[size];
 cout<<"Enter the values"<<endl;
 for(int i=0;i<size;i++)
 cin>>arr[i];
 cout<<"Enter the value of k"<<endl;
 cin>>k;
}
 void repeating();

~repeating_number(){
 delete [] arr;
}
};

void repeating_number::repeating(){
 int i,max,val;
 for(i=0;i<size;i++)
  arr[arr[i]%k]+=k;
 max=arr[0];
 for(i=1;i<size;i++){
  if(arr[i]>max){
   max=arr[i];
   val=i;
}
}
 cout<<"maximum repeating number is "<<val<<endl;
}

int main(void){
 repeating_number ob;
  ob.get();
  ob.repeating();
}
