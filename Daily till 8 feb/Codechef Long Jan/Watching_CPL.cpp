#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include<unordered_map>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define endl            '\n'
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

 

#define mod 1000000007

using namespace std;
using ll = long long;

int solve(int *h,int k1,int k2,int i,int n,map<pair<int,int>,int> &dp){
    // base cases
    //db1(i);
    if(i==n) {
        if(k1<=0 && k2<=0){
            return 0;
        }else{
            return INT_MAX;
        }
        
    }
    //db2(k1,k2);
    if(k1<=0 && k2 <=0) return 0;
    if( dp.find(mp(k1,k2)) != dp.end() )  return dp.at(mp(k1,k2));
    int opt1=INT_MAX,opt2=INT_MAX,opt3=INT_MAX,opt4=INT_MAX;
    if(k1>0){
       
        opt1= 1+ solve(h,k1-h[i],k2,i+1,n,dp);
        opt2= solve(h,k1,k2,i+1,n,dp);
    }
    if(k2>0){
        opt3= 1+ solve(h,k1,k2-h[i],i+1,n,dp);
        opt4= solve(h,k1,k2,i+1,n,dp);
    }

    return dp[{k1,k2}] =min(min(opt1,opt2),min(opt3,opt4));

}

int32_t main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif 
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int *h= new int[n];
        
        for(int i=0;i<n;i++) cin>>h[i];
         
        
        map<pair<int,int>,int> dp;
        int ans= solve(h,k,k,0,n,dp);
        cout<<ans<<"\n";
    }
    return 0;
}