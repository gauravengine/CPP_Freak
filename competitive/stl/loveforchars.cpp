#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int total_size,count_a=0,count_s=0,count_p=0;
  cin>>total_size;
  cin>>s;
  for(int i=0;i<total_size;i++){
    if(s[i]=='a') count_a++;
    if(s[i]=='s') count_s++;
    if(s[i]=='p') count_p++;

  }
  cout<<count_a<<" "<<count_s<<" "<<count_p;
}
