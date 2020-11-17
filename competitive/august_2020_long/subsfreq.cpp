#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
const unsigned int M = 1000000007;



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  

  ll *dp= new ll[500000];
  dp[0]= 1;
  for(int i=1;i<500000;i++){
      dp[i] = ( dp[i-1]*2 )% M;
  }


  while(t--){
   int n;
   cin>>n;
   int* arr= new int[n+1]();
   unordered_map<int,int> freq;
   bool flag= true;   


   for(int i=1;i<=n;i++){
    cin>>arr[i];
    freq[arr[i]] ++;
    if(freq[arr[i]] > 1) flag = false;
   }
   
  if(flag){  // sub- 2 case
    for(int i=n-1;i>=0 ;i--){
      cout<<dp[i]<<" ";
    }

    cout<<endl;
  }


   else{
    // for - 20 points 


   }

    
  }



return 0;
}