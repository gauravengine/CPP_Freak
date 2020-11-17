#include<iostream>
using namespace std;
int main(){
int n; int rev=0;
cin>>n;
do {
rev=rev*10 +(n%10);
n=n/10;
}while( (n/10)!=0);
rev=rev*10 + n;

cout<<rev;
return 0;
}
