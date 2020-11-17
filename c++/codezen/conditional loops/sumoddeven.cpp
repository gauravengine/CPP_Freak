#include<iostream>
using namespace std;
int main(){
  int n; int sumeve=0,sumodd=0;
  cin>>n;
  int temp=n;
  while(temp>0){
 if(temp%2) sumodd+=temp%10;
 else sumeve+=temp%10;
 temp=temp/10;



} cout<<sumeve<<" "<<sumodd;
}
