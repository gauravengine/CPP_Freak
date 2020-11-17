#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n; int arr[n][n];
for(int row=0;row<n;row++){
for(int column=0;column<n;column++){
cin>>arr[row][column];
}
  }
int sum=0;
for(int row=0;row<n;row++){
for(int column=0;column<n;column++){
if(row==0||row==(n-1)||column==0||column==(n-1)||row==column||column==(n-row-1)) {cout<<arr[row][column]<<" "; sum+=arr[row][column]; }
} cout<<endl;
  }
cout<<sum;
return 0;
}
