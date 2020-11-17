#include<iostream>
using namespace std;

int fibbo(int n){
if(n==1||n==2) {return 1;}
 else{  return fibbo(n-1) +fibbo(n-2);

}
}
int main(){ int j;
  cin>>j;
  cout<<fibbo(j);



}
