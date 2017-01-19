#include<iostream>
#include<algorithm>

using namespace std;

class sum_pair{
  private:
   int n,sum;
   int *arr;
   bool l;
  public:
   sum_pair(int size=4,int s=0){
   n=size;
   sum=0;
   l=false;
}
  void get(){
   cout<<"Enter the size of array"<<endl;
   cin>>n;
   arr=new int[n];
   cout<<"Enter the values"<<endl;
   for(int i=0;i<n;i++)
    cin>>arr[i];
   cout<<"Enter the sum"<<endl;
   cin>>sum;
}
  void pair();
  ~sum_pair(){
   delete [] arr;
}
};

int binary_search(int arr[],int low,int high,int val){
  int mid;
  if(low<=high){
   mid=(low+high)/2;
   if(arr[mid]==val)
   return mid;
   else if(arr[mid]>val)
   return binary_search(arr,low,mid-1,val);
   else
    return binary_search(arr,mid+1,high,val);
}
return -1;
}
void sum_pair::pair(){
  int i,j,k,v,x,s;
  sort(arr,arr+n);
  for(i=0;i<n-1;i++){
   j=i+1;
   k=n-1;
   while(j<k){
   s=arr[i]+arr[j]+arr[k];
   v=sum-s;
   
    if(s>=sum)
     k--;
    else if(v==arr[i]||v==arr[j]||v==arr[k])
     j++;
    else{
      x=binary_search(arr,0,n-1,v);
      if(x==-1){
        if(v<arr[k])
          k--;
        else
          j++;
}
      else{
       l=true;
      cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<<arr[x]<<endl;
      j++;
}
}
}
}
if(l==false)
cout<<"No such pair"<<endl;
}

int main(void){
sum_pair ob;
ob.get();
ob.pair();
}
