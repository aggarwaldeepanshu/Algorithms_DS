#include<iostream>
#include<cstdlib>
using namespace std;

class shuffle{
  private:
  int size;
  int *arr;

  public:
  shuffle(int n=4){
   size=n;
   arr=new int[size];
}
  void get(){
  cout<<"Enter the array size"<<endl;
  cin>>size;
  arr=new int[size];
  cout<<"Enter the elements"<<endl;
  for(int i=0;i<size;i++)
  cin>>arr[i];
}
  void shuffled_array();

  void display(){
   cout<<"The array after shuffling is"<<endl;
   for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}
  ~shuffle(){
   delete [] arr;
}
};

void swap(int arr[],int j,int i){
  int temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
}

void shuffle::shuffled_array(){
  int j;
 for(int i=size-1;i>0;i--){
   j=rand()%(i+1);
   swap(arr,j,i);
}
}

int main(void){
 shuffle ob;
  ob.get();
  ob.shuffled_array();
  ob.display();
}
