#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int N,M;
  cin>>N>>M;
  ll arr[N];
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  sort(arr,arr+N);
queue<ll> q;
int count_m=0;
int end_p=N-1;
while(M--){
  ll ans;
  int curr_query; cin>>curr_query;
  for(;count_m<curr_query;count_m++){
  if(end_p>=0 &&(q.empty()||arr[end_p]>=q.front())){
    ans=arr[end_p]; end_p--;
  }
  else{
    ans=q.front(); q.pop();
  }
  q.push(ans/2);
  }
cout<<ans<<endl;
}


return 0;
}
