#include<bits/stdc++.h>
using namespace std;
int lastIndex(int input[],int size,int x){
/*  if(size==1) {
    if(input[0]==x) return size-1;
    else return -1;
  }
  int smallans=lastIndex(input,size-1,x);
  if(smallans!=-1){
    return size-1;
  }
  else {
    if(input[size-1]==x) return size-1;
    else return -1;
  }*/
if(size==0) return -1;

int smallans=lastIndex(input+1,size-1,x);

if(smallans!=-1) {
  return smallans+1;
}
else if( smallans==-1){
  if(input[0]==x) return 0;
  else return smallans;
}

}





int main(){
int size;
cin>>size; int input[size];

for(int i=0;i<size;i++)
{
  cin>>input[i];
}
  int x ; cin>>x;
  cout<<lastIndex(input,size,x);
  return 0;
}
