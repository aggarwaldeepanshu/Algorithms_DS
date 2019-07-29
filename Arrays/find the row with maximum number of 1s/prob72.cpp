#include<iostream>
using namespace std;

class Row{
  private:
  int row,col;
  int **arr;
  public:

  Row(int r=2,int c=2){
  row=r;
  col=c;
   arr=new int *[row];
   for(int i=0;i<row;i++)
   arr[i]=new int[col];
   //arr=new int[row*col];
}

  void get(){
  cout<<"Enter the number of rows"<<endl;
  cin>>row;
  cout<<"Enter the number of columns"<<endl;
  cin>>col;
   arr=new int *[row];
   for(int i=0;i<row;i++)
   arr[i]=new int[col];
  cout<<"Enter the values"<<endl;
  for(int i=0;i<row;i++)
   for(int j=0;j<col;j++)
     cin>>arr[i][j];
}

  void max_row();

  void display(int r){
   cout<<"Row with maximum 1's is"<<" "<<r+1<<endl;
}

  ~Row(){
  for(int i=0;i<row;i++)
   delete [] arr[i];
  delete [] arr;
}
};

void Row::max_row(){
  int i,j,v=-1,val;
  j=col-1;
  while(j>=0){
   if(arr[0][j]==0){
     v=j+1;
     break;
}
  j--;
}
  if(v==-1)
   v=0;
   val=0;
  for(i=1;i<row;i++){
  if(v==0)
   break;
  if(arr[i][v-1]==1){
   j=v-1;
   val=i;
   while(j>=0){
    if(arr[i][j]==0)
     break;
    else{
     v=j;
     j--;
}
}
}
}
  display(val);
}

int main(void){
 Row ob;
 ob.get();
 ob.max_row();
}
