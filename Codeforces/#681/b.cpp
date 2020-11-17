// Created by Yadav_Gaurav
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define mod 1000000007

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<pair<int,int>>  segment;
        int a ,b;
        string s;
        cin>>a>>b>>s;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='0'){
                continue;
            }
            else{
                int j=i;
                while(s[j+1] != '0' && j+1<s.length()){
                    j++;
                 
                }
                segment.push_back(make_pair(i,j));
                   
                i=j+1;
            }
        }
        int cost=0;
        if(segment.size() >= 1) cost +=a;

        bool previous= false;
        for(int i=1;i<segment.size();i++){
            
            // if((segment[i+1].first-segment[i+1].second)*b <= a && (i+1<segment.size())){
            //     if(!previous){
            //      cost+= a+b*(segment[i+1].first-segment[i+1].second);
            //      previous=true;
            //     }
            //     else{
            //         cost+=b*(segment[i+1].first-segment[i+1].second);
            //     }
            //     //i=i+2;
            // }
            // else{
            //     cost+=a;
            //     previous=false;
            // }
            if((segment[i].first-segment[i-1].second-1)*b <= a){
                cost+= (segment[i].first-segment[i-1].second-1)*b;
            }
            else{
                cost+=a;
            }

        }
        cout<<cost;
        cout<<'\n';
    }
    return 0;
}