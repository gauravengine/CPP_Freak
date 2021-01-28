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

int solve(int n,int* dp){
    if(n<1) return 1e8;
    if(n==1) return 0;
    if(dp[n] > -1) return dp[n];
    int ans1=1+solve(n-1,dp);
    int ans2=INT_MAX;
    int ans3=INT_MAX;
    if(n%2==0) ans2=1+solve(n/2,dp);
    if(n%3==0) ans3=1+ solve(n/3,dp);
    return dp[n]=min(ans1,min(ans2,ans3));
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
    int t; cin>>t;
    for(int i=1;i<=t;i++){
        int n; cin>>n;
        int* dp= new int[n+1];
        for(int j=0;j<=n;j++) dp[j]=-1;
        int ans= solve(n,dp);
        cout<<"Case"<<" "<<i<<": "<<ans<<endl;
    }
    return 0;
}