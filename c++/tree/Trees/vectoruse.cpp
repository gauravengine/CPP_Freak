#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v[3]=1000;
  v[4]=2000;
  cout<<v[0]<<endl;
  cout<<v[1]<<endl;
  cout<<v[2]<<" "<<v[3]<<" "<<v[4]<<endl;
  cout<<"size is: "<<v.size()<<endl;
  cout<<v.at(4);
}
