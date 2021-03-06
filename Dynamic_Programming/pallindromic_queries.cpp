#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define ff              first
#define endl            '\n'
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

bool solve(int l,int r,string &s,int** dp){
    if(l>r) return true;
    if(dp[l][r] >-1) return dp[l][r];
    
    return dp[l][r]=solve(l+1,r-1,s,dp) && (s[l]==s[r]);

}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif 
    int n; cin>>n;
    string s; cin>>s;
    int** dp= new int*[n];
    for(int i=0;i<n;i++){
        dp[i]= new int[n];
        for(int j=0;j<n;j++) dp[i][j]=-1;
    }
    int q; cin>>q; 
    while(q--){
        int l,r; cin>>l>>r;
        l--; r--;
        if(solve(l,r,s,dp)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}