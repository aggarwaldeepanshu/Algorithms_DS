#include<stdio.h>
#define N 8

int search(int arr[][N],int x,int y);

int main(void){
int i,j,n,x,y,v;
printf("Enter the size\n");
scanf("%d",&n);
int arr[N][N];
printf("Enter the relation between people in terms of 0 or 1\n");
for(i=0;i<n;i++)
  for(j=0;j<n;j++)
    scanf("%d",&arr[i][j]);
x=0;
y=n-1;
while(x<y){
   if(search(arr,x,y))
   x++;
   else
   y--;
}
v=x;
for(i=0;i<n;i++){
  if(i!=x && search(arr,x,i)){
   v=-1;
   break;    
}
}
if(v==-1)
printf("There is no celebrity\n");
else
printf("The celebrity is %d\n",v);
}

int search(int arr[][N],int x,int y){

return arr[x][y];
}
