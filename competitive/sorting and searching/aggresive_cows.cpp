#include<bits/stdc++.h>
using namespace std;
bool possible(long long arr[],int n,int cows,long long distance){
  int count =1;
   long long least= arr[0];// cout<<"i m here"; int i=0;
/*  while(i<n&& count<=cows){
    if((arr[i]-least)>=distance){
      least=arr[i];// cout<<"i m here 1";
      i++; count++;// cout<<count<<endl;
    }
else i++;

  }
  if(count<cows) { return false ; }
  else{
    return  true;} */
    for(int i=0;i<n;i++){
      if((arr[i]-least)>=distance){
        count++; least=arr[i];
      }
      if(count==cows) {return true; }
    }

return false;
}
int main(){
  int t;cin>>t;
  while(t--){
int n; int c;
cin>>n; cin>>c;
long long arr[n];
for(int i=0;i<n;i++){
  cin>>arr[i];
}
sort(arr,arr+n);
long long start=0; long long ans=-1; //long long mid;
long long  end=arr[n-1]-arr[0];
while(start<=end){
    long long mid=start + (end-start)/2; //cout<<mid<<endl;
  if(possible(arr,n,c,mid)){
    start=mid+1;
    ans=mid; //cout<<ans<<endl;
  }
  else {
    end=mid-1;
  }



}
cout<<ans;
  }
  return 0;
}
