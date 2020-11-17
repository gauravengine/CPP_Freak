#include<bits/stdc++.h>
using namespace std;
int main() {
int total_marbles,target_number;
cin>>total_marbles>>target_number; int a[total_marbles];
for(int i=0;i<total_marbles;i++){
cin>>a[i];
  }
for(int i=0;i<total_marbles-1;i++){
  if(a[i+1]==target_number) {cout<<"true"<<endl<<a[i+1];return 0;}
  if(a[i]==target_number) {cout<<"true"<<endl<<a[i];return 0;}

  if(a[i]+a[i+1]==target_number) {
    cout<<"true"<<endl; cout<<a[i]<<" "<<a[i+1]; return 0;
  }
}
	cout<<"false"; return 0;
}
