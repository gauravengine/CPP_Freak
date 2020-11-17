#include<bits/stdc++.h>
using namespace std;
int warm(int *arrival_times,int *departure_times,int size){
sort(arrival_times,arrival_times+size);
sort(departure_times,departure_times+size);
int i=0,j=0;
int ans=0,curr_customer_count=0;
while(i<size||j<size){
  if(arrival_times[i]<=departure_times[j])
  {
    curr_customer_count++;
    i++;
    if(curr_customer_count>ans) ans=curr_customer_count;
  }
  else{
    curr_customer_count--;
    j++;
  }
}

return ans;
}
int main(){
  int n;
  cin>>n;
  int arrival_times[n],departure_times[n];
  for(int i=0;i<n;i++){
    cin>>arrival_times[i];
  }
  for(int i=0;i<n;i++){
    cin>>departure_times[i];
  }

cout<<warm(arrival_times,departure_times,n);
  return 0;
}
