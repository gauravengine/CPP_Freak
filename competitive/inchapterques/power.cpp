#include<bits/stdc++.h>
using namespace std;
int count(int n){
    if(n == 0){
        return 1;
    }
    int smallAns = count(n / 10);
    return smallAns +1 ;
}
int main(){
  int n; cin>>n;
  cout<<count(n);
  return 0;
}
