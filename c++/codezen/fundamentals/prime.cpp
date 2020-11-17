#include<iostream>
using namespace std;
  bool primecheck(int a){  if(a==1) return false;
   if(a==2) return true;
if (a%2==0) return false;
for(int i=3; i<a;i+=2){
  if(a%i==0) return false;
}
   return true;
 }
int main(){
int n;
cin>>n;
for(int j=2;j<=n;j++){
if(primecheck(j)) cout<<j<<endl;


}

}
