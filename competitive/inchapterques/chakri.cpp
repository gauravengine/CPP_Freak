#include<bits/stdc++.h>
using namespace std;
int main(){
int numofdays;
cin>>numofdays; int arr[numofdays];
for(int i=0;i<numofdays;i++){
  cin>>arr[i];
}
int diff=0;
for(int i=0;i<numofdays-1;i++)
{
  for(int j=i;j<numofdays-1;j++){
    if(arr[j+1]-arr[i]>diff) diff=arr[j+1]-arr[i];
  }
}
cout<<diff;
return 0;
}
