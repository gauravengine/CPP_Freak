#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("taktakin.txt","r",stdin);
//freopen("taktakout.txt","w",stdout);
int init,m=0,n=2;
cin>>init;
 if((init-1)%11==0) {  cout<<"0"<<" "<<init; }
else {
while(((init*(2*n)-1)%11==0))
{ m++ ;

  n=n*2;}
cout<<m<<" "<<init*(2*n);

}





  return 0;
}
