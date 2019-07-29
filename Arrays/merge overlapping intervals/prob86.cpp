#include<iostream>
#include<algorithm>
#include<utility>
#define max 80
using namespace std;

class intervals{
private:
 int size;
 pair<int ,int> p[max];

public:
intervals(int n=4){
 size=n;
}
void get(){
 cout<<"Enter the size"<<endl;
 cin>>size;
 cout<<"Enter the values"<<endl;
 for(int i=0;i<size;i++)
 cin>>p[i].first>>p[i].second;
}
 void merge_interval();
 void display(){
  cout<<"The required intervals"<<endl;
  for(int i=0;i<size;i++)
   if(p[i].first!=-1&&p[i].second!=-1)
     cout<<"["<<p[i].first<<","<<p[i].second<<"]"<<" ";
}
};

void intervals::merge_interval(){
 int i;
 sort(p,p+size);
 for(i=0;i<size-1;i++){
  if(p[i].second>=p[i+1].first){
    p[i+1].first=(p[i].first<=p[i+1].first)?p[i].first:p[i+1].first;
    p[i+1].second=(p[i].second>=p[i+1].second)?p[i].second:p[i+1].second;
    p[i].second=p[i].first=-1;
}
}
}

int main(void){
 intervals ob;
  ob.get();
  ob.merge_interval();
  ob.display();
}
