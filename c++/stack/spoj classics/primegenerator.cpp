#include<iostream>
using namespace std;
bool primecheck(int );
int main(){
int t;
cin>>t;
while(t--){
  int m,n; cin>>m; cin>>n;
  for (double i=m;i<=n;i++)
  {
    if(primecheck( i)) {
      cout<<i<<endl;
    }
  } cout<<endl;
} return 0; }
 bool primecheck(int a){  if(a==1) return false;
   if(a==2) return true;
if (a%2==0) return false;
for(int i=3; i<a;i+=2){
  if(a%i==0) return false;
}
   return true;
 }
