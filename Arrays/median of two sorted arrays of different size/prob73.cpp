#include<iostream>
using namespace std;

class median{
private:
 int size1,size2;
 int *arr1,*arr2;

public:
 median(int n=4,int m=4){
  size1=n;
  size2=m;
  arr1=new int[size1];
  arr2=new int[size2];
}
 void get(){
  int i;
  cout<<"Enter the size of first array"<<endl;
  cin>>size1;
  arr1=new int[size1];
  cout<<"Enter the values"<<endl;
  for(i=0;i<size1;i++)
  cin>>arr1[i];
  cout<<"Enter the size of second array"<<endl;
  cin>>size2;
  arr2=new int[size2];
  cout<<"Enter the values"<<endl;
  for(i=0;i<size2;i++)
  cin>>arr2[i];
}

 int find_median();

void display(int v){
 cout<<"Median is "<<v<<endl;
}
};

int mid_value(int arr[],int n){
  if(n%2==0)
  return (arr[n/2]+arr[n/2-1])/2;
  else
  return arr[n/2];
}

int max(int a,int b){
 return (a>b)?a:b;
}

int min(int a,int b,int c){
 return (a>b)?b:a;
}

int median_of_three(int a,int b,int c){
 int l,q,v;
  l=max(a,max(b,c));
  q=min(a,min(b,c));
  v=a+b+c-l-q;
  return v;
}

int median_of_four(int a,int b,int c,int d){

return (a+b+c+d-max(a,max(b,max(c,d)))-min(a,min(b,min(c,d))))/2;
}

int find(int arr1[],int m,int arr2[],int n);

int median::find_median(){
 int v;
  if(size1>size2)
   v=find(arr1,size1,arr2,size2);
  else
   v=find(arr2,size2,arr1,size1);
  display(v);
}

int find(int arr1[],int m,int arr2[],int n){
int m1,m2,diff;
 if(n==0&&m==2)
  return (arr1[0]+arr1[1])/2;

 else if(n==1&&m==1)
  return (arr1[0]+arr2[0])/2;

 else if(n==1&&m%2!=0){
 int v;
  v=median_of_three(arr1[m/2-1],arr2[0],arr1[m/2+1]);
  return (v+arr1[m/2])/2;
}

 else if(n==1&&m%2==0){
  if(arr2[0]<arr1[m/2-1])
   return arr1[m/2-1];
  else if(arr2[0]>arr1[m/2])
   return arr1[m/2];
  else
   return arr2[0];
}

 else if(m==2&&n==2)
  return median_of_four(arr1[0],arr1[1],arr2[0],arr2[1]);

 else if(n==2&&m%2!=0)
  return median_of_three(arr1[m/2],max(arr2[0],arr1[m/2-1]),min(arr2[1],arr1[m/2+1]));

else if(n==2&&m%2==0)
  return median_of_four(arr1[m/2],arr1[m/2-1],max(arr2[0],arr1[m/2-2]),min(arr1[m/2+1],arr2[1]));

else{
 diff=(m-1)/2;
 m1=mid_value(arr1,m);
 m2=mid_value(arr2,n);
 if(m1>m2)
  return find(arr1,m-diff,arr2+diff,n/2+1);
 else
  return find(arr1+diff,m-diff,arr2,n/2+1);
}
}

int main(void){
 median ob;
 ob.get();
 ob.find_median();
}

