#include<bits/stdc++.h>
using namespace std;
int firstIndex(int input[],int size,int x){
  if(size==1) {
    if(input[0]==x) return size-1;
    else return -1;
  }
  int smallans=firstIndex(input,size-1,x);
  if(smallans!=-1){
    return smallans;
  }
  else {
    if(input[size-1]==x) return size-1;
    else return -1;
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
  cout<<firstIndex(input,size,x);
  return 0;
}
