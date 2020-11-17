#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n  ;
        cin>>n;
        string a,b;
        cin>>a>>b;
        set<char> a1,b1;
        for(auto x:a){
            a1.insert(x);
        }
        for(auto x:b){
            b1.insert(x);
        }
        /*
        for(auto it:a1){
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it: b1){
            cout<<it<<" ";
        } */
        

    }

    return 0;
}