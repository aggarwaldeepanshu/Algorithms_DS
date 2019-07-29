#include<iostream>
using namespace std;

class monotonic_function{
public:
void function();
};

int foo(int v){
  return (v*v*v);
}

int binary_search(int low,int high){
 int mid;
 mid=(low+high)/2;
 if(low==high)
  return low;
 if(low<high){
   if(foo(mid)>0&&foo(mid-1)<0)
    return mid;
   else if(foo(mid)<0&&foo(mid+1)>0)
    return mid+1;
   else if(foo(mid)>0&&foo(mid-1)>0)
    return binary_search(low,mid-1);
   else if(foo(mid)<0&&foo(mid+1)<0)
    return binary_search(mid+1,high);
}
}

void monotonic_function::function(){
int i,v,j;
 if(foo(0)>0)
 // cout<<"The desired point is "<<0<<endl;
  i=0;
 else if(foo(1)>0)
  //cout<<"The desired point is "<<1<<endl;
  i=1;
 else{
  j=2;
  v=2;
  while(foo(v)<0)
   v=2*v;
  i=binary_search(j,v);
}
 cout<<"The desired point is "<<i<<endl;
}

int main(void){
 monotonic_function ob;
 ob.function();
}
