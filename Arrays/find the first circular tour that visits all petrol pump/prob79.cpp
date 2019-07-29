#include<iostream>
#include<utility>
#define max 100
using namespace std;

class tour{
private:
  int size;
  pair <int,int> p[100];

public:
tour(int n=4){
 size=n;
}
void get(){
 cout<<"Enter the array size"<<endl;
 cin>>size;
 cout<<"Enter the values"<<endl;
 for(int i=0;i<size;i++)
 cin>>p[i].first>>p[i].second;
}
int first_pump();

void display(int n){
  if(n==-1)
  cout<<"Not possible"<<endl;
  else
  cout<<"The required answer is "<<n<<endl;
}
};

int tour::first_pump(){
int ptrl,i,start,end,j;
 for(i=0;i<size;i++){
  start=i;
  end=-1;
  ptrl=p[i].first-p[i].second;
  j=i;
  while(ptrl>=0&&end!=start){
   j=(j+1)%size;
   ptrl+=(p[j].first-p[j].second);
   end=(j+1)%size;
}
 if(end==start)
  return start;
}
 return -1;
}

int main(void){
 tour ob;
 ob.get();
int i=ob.first_pump();
 ob.display(i);
}
