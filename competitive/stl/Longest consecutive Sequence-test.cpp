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

  for(int i=0;i<n;i++){
    int j=1; int curr_max=1;
if(m[arr[i]]==true) {
  m[arr[i]]=false;
    while(auto it=m.find(arr[i]+j)!=m.end())
    {
      cout<<arr[i]+j<<" ";
  curr_max++;   m[arr[i]+j]=false; j++;
} cout<<endl;
int j=1;
    while(auto it=m.find(arr[i]-j)!=m.end()){
      cout<<arr[i]-j<<" ";
  curr_max++; m[arr[i]-j]=false;  j++;
} cout<<endl;
cout<<"answer after "<<i+1<<" iteration : "<<curr_max<<endl;
if(curr_max>ans) ans=curr_max;
}

  }
  cout<<"the final answer is :"<<ans;
  return 0;
}
