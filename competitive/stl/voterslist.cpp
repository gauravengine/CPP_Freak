#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int main(){
int n1,n2,n3;
cin>>n1>>n2>>n3;
unordered_map<int,int> m;
for(int i=0;i<n1+n2+n3;i++){
  int a; cin>>a;
  m[a]++;
}
std::vector<int> v;
int count=0;
unordered_map<int,int>::iterator mi;
for(mi=m.begin();mi!=m.end();mi++){
  if(mi->second>=2){ v.push_back(mi->first);
    count++;
} }
cout<<count<<endl;
vector<int>::iterator vi;
sort(v.begin(),v.end());
for(vi=v.begin();vi!=v.end();vi++){
  cout<<*vi<<endl;
}






  return 0;
}
