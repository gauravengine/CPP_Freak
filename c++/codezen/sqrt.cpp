#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n; if(n==0) cout<<0;
    for (int i=1;i<n;i++){

        if(((i*i) <=n) &&(i+1)*(i+1)>n) {cout<<i; }
    }


    return 0;
}
