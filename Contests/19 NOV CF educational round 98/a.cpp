// Created by yadav_gaurav
#include <bits/stdc++.h>
#define inf (1<<30)
#define mod 1000000007
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'

using namespace std;
using ll = long long;
set<pair<int,int>> s;
ll solve(int x, int y, int fi, int fj,int m){

	//db2(x,y);
    
	if(x ==fi && y== fj){
		return 0;
	}
	if(x> fi || x<0 || y> fj ||y <0 ){
		return inf;
	}
	if(s.find({x,y}) != s.end()){
          return inf;
           
       } 
        else{
            s.insert({x,y});
            
            
        }
 	ll n = solve(x,y+1,fi,fj,m);
	ll s=  solve(x,y-1,fi,fj,m);
	ll w = solve(x-1,y,fi,fj,m);
	ll e=  solve(x+1,y,fi,fj,m);
	return 1+ min(min(n,s),min(e,w));

}

int main()
{		ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin>>t;
    //cout<<"hello";
    while(t--){
      //	cout<<"hello";
        int x,y; cin>>x>>y;
       int m=0;
        ll ans= solve(0,0,x,y,m);
        cout<<ans;
        
        cout<<'\n';
    }
    
    return 0;
}