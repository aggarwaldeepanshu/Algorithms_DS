#include<iostream>
using namespace std;

class pancake_sorting{
private:
 int size;
 int *arr;

public:

pancake_sorting(int n=4){
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

void flip(int arr[],int n){
int i=0,temp;
while(i<n){
 temp=arr[i];
 arr[i]=arr[n];
 arr[n]=temp;
 n--;
 i++;
}
}

int max(int arr[],int n){
int i,max,temp;
 max=0;
  for(i=1;i<=n;i++){
   if(arr[i]>arr[max]){
    max=i;
}
}
return max;
}

void pancake_sorting::sort(){
 int n,val;
 n=size-1;
 while(n>0){
 val=max(arr,n);
 if(val!=n){
  flip(arr,val);
  flip(arr,n);
}
n--;
}
}
int main(void){
 pancake_sorting ob;
 ob.get();
 ob.sort();
 ob.display();
}
