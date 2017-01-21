#include<iostream>
#include<algorithm>
using namespace std;

class triangles{
private:
 int size;
 int *arr;
  
public:

triangles(int n=4){
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
void number_triangles();

void display(int count){
cout<<"Number of possible triangles are"<<" "<<count<<endl;
}
~triangles(){
delete [] arr;
}
};

void triangles::number_triangles(){
  int k,count;
  sort(arr,arr+size);
  count=0;
 for(int i=0;i<size-2;i++){
   k=i+2;
   for(int j=i+1;j<size;j++){
     while((arr[i]+arr[j])>arr[k]&&k<size){
       k++;
}
  count=count+(k-j-1);
}
}
display(count);
}

int main(void){
triangles ob;
ob.get();
ob.number_triangles();
}
