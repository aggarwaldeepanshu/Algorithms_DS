#include<iostream>
using namespace std;

class elements{
private:
 int size,k;
 int *arr;

public:

elements(int n=4,int m=2){
 size=n;
 arr=new int[size];
 k=m;
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
void number_of_elements();
~elements(){
 delete [] arr;
}
};

void elements::number_of_elements(){
  pair<int,int> p[k-1];
  int i,j,m;
  for(i=0;i<k-1;i++){
   p[i].second=0;
   p[i].first=-1;
}
  p[0].first=arr[0];
  p[0].second=1;
  m=1;
  for(i=1;i<size;i++){
   for(j=0;j<k-1;j++){
     if(arr[i]==p[j].first){
       p[j].second++;
       break;
}
}
  if(j==k-1){
   p[m].first=arr[i];
   p[m].second=1;
   m++;
}
}

 cout<<"Number appearing more than n/k times:"<<endl;
  for(i=0;i<k-1;i++){
   if(p[i].second>(size/k))
    cout<<p[i].first<<" ";
}
}

int main(void){
 elements ob;
 ob.get();
 ob.number_of_elements();
}
