#include<iostream>
using namespace std;

struct tree{
 int data;
 tree*left;
 tree *right;
};

class increasing_subsequence{
private:
 int size;
 int *arr;

public:

increasing_subsequence(int n=4){
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
void maximum_product();
~increasing_subsequence(){
 delete [] arr;
}
};

tree *new_node(int d){
 tree *node=new tree;
 node->data=d;
 node->left=NULL;
 node->right=NULL;
 return node;
}

tree *insert(tree *root,int d,int &min){
 if(root==NULL)
  return new_node(d);
 else if(root->data>d)
  root->left= insert(root->left,d,min);
 else{
  min=(min>root->data)?min:root->data;
   root->right= insert(root->right,d,min);
}
 return root;
}

void increasing_subsequence::maximum_product(){
int i,j,min,max,min_max,val;
int small[size],large[size];

tree *root=new tree;
 root=NULL;
for(i=0;i<size;i++){
 min=-1;
 root=insert(root,arr[i],min);
 small[i]=min;
}

max=arr[size-1];
large[size-1]=-1;
for(i=size-2;i>=0;i--){
 if(arr[i]>max){
  large[i]=-1;
  max=arr[i];
}
 else
  large[i]=max;
}
max=0;
for(i=0;i<size;i++){
 if(small[i]!=-1&&large[i]!=-1){
   val=large[i]*small[i]*arr[i];
    if(val>max){
      max=val;
      j=i;
}
}
}
cout<<"The required subsequence is "<<endl;
cout<<small[j]<<" "<<arr[j]<<" "<<large[j]<<endl;
}
int main(void){
 increasing_subsequence ob;
 ob.get();
 ob.maximum_product();
}
