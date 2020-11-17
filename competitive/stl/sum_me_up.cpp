#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
int t;
cin>>t;
while(t--){
  ll x; ll sum=0;
  while(x>0){
    sum+=x%10;
    x=x/10;
  }
  cout<<sum<<endl;
}

}
