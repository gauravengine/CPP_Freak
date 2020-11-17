#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n; int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  unordered_map<int ,bool> m;
  for(int i=0;i<n;i++){
    m[arr[i]]=true;
  }
  int  ans=0;
vector<int> v[n];
  for(int i=0;i<n;i++){
    int j=1; int curr_max=1;
if(m[arr[i]]==true) {
  v[i].push_back(arr[i]);
  m[arr[i]]=false;
    while(m[arr[i]+j]==true){
    //  cout<<arr[i]+j<<" ";
  curr_max++;
v[i].push_back(arr[i]+j);
    m[arr[i]+j]=false;
   j++;
} //cout<<endl;
int j=1;
    while(m[arr[i]-j]==true){
      //cout<<arr[i]-j<<" ";
  curr_max++;
v[i].push_back(arr[i]-j);
   m[arr[i]-j]=false;  j++;
} //cout<<endl;
//cout<<"answer after "<<i+1<<" iteration : "<<curr_max<<endl;
if(curr_max>ans) ans=curr_max;
}

  }
  for(int i=0;i<n;i++){
    if(v[i].size()==ans){
      for(auto it=v[i].begin();it!=v[i].end();it++)
      {
        cout<<*it<<" ";
      }
    }
}
//  cout<<"the final answer is :"<<ans;
  return 0;
}
