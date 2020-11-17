#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("sitin.txt","r",stdin);
freopen("sitout.txt","w",stdout);
int r,s,ticks;
cin>>r>>s>>ticks;
if(ticks>=r*s){
  cout<<r*s <<" "<<ticks-r*s;

}
else {
cout<<ticks<<" "<<"0";

}


  return 0;
}
