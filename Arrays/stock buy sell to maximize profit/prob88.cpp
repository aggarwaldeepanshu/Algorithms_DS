#include<iostream>
#define max 80
using namespace std;

class stock{
private:
 int size;
 int *arr;

public:
 stock(int n=4){
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
 void buy_sell();
 ~stock(){
   delete [] arr;
}
};

void stock::buy_sell(){
 int i,j,count=0;
  pair<int,int> p[max];
  j=0;
  i=0;
  while(i<size){
   while(i<size-1&&arr[i]>=arr[i+1])
    i++;
   if(i==size-1)
    break;
   p[j].first=i;
   while(i<size&&arr[i]<=arr[i+1])
     i++;
   p[j].second=i;
   j++;
   count++;
}
 if(count==0)
  cout<<"No such pair"<<endl;
 else
  for(i=0;i<j;i++)
   cout<<"Buy on day "<<p[i].first<<"  Sell on day "<<p[i].second<<endl;
}

int main(void)
{
 stock ob;
 ob.get();
 ob.buy_sell();
}
