#include<bits/stdc++.h>
using namespace std;
bool checknumber(int input[],int size,int x){
  if(size==1) {
    if(input[0]==x) return true;
    else return false;
  }
  bool smallans;
  if(checknumber(input,size-1,x)==true) smallans=true;
  else smallans=false;
if(smallans==true) return true;
else if(input[size-1]==x) return true;
else return false;



}

int main(){
int size;
cin>>size; int input[size];

for(int i=0;i<size;i++)
{
  cin>>input[i];
}
  int x; cin>>x;
  if(checknumber(input,size,x))
  {
    cout<<"true"<<endl;
  }
  else cout<<"false"<<endl;
  return 0;
}
