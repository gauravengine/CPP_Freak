#include<iostream>
using namespace std;
int main(){
 int n;// int totalstarsinrow,starsprinted=0;
 cin>>n;
 for(int row=1;row<=n;row++){
//totalstarsinrow=2*row-1;
   for(int column=1;column<=(2*n-1);column++){
//if (row==1&& column==(2*n-1)/2 +1) {cout<<"*"; }
if(column<n-row+1||column>=n+row) cout<<" ";
else cout<<"*";


   } cout<<endl;

 }

}
