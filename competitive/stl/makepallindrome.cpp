#include<bits/stdc++.h>
using namespace std;
int main(){
int testcases;
cin>>testcases;
while(testcases--){
  string s; 
  cin>>s;
  map<char,std::vector<int> > m;
  int address_count=1;
  string::iterator si;
  for(si=s.begin();si!=s.end();si++){
    m[*si].push_back(address_count);
    address_count++;
  }

cout<<testcases;

}


  return 0;
}
