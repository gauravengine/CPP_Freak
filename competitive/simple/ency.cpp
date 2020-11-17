#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
int main(){
  //freopen("encyin.txt","r",stdin);
  //freopen("encyout.txt","w",stdout);
 int n,query; cin>>n>>query;
 int arr[n];
 for(int i =0;i<n;i++){

   cin>>arr[i];
 }
for(int i=0;i<query;i++){
int page;
cin>>page;
cout<<arr[page-1]<<endl;


}
return 0;

}
