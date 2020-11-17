#include<iostream>
using namespace std;
int main(){
  int n; int sum=0;
  int c; double pro=1;
  cin>>n; cin>>c;
  if(c==1){
    for(int i=1;i<=n;i++){
      sum+=i;
    }
    cout<<sum;
  }
else if(c==2){
  for(int i=1;i<=n;i++){
    pro*=i;

  } cout<<pro;
}
else {
  cout<<"-1";

}
return 0;








}
