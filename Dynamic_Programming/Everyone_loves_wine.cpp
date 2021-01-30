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

int solve(int* arr,int n ,int l,int r,int** dp){
    if(l>r) return 0;
    
    int age= l+ n-r;
    if(l==r) return age*arr[l];

    if(dp[l][r] >-1) return dp[l][r];

    int opt1= INT_MIN;
    int opt2= INT_MIN;
    opt1=age*arr[l]+ solve(arr,n,l+1,r,dp);
    opt2= age*arr[r]+solve(arr,n,l,r-1,dp);

    return dp[l][r]=max(opt1,opt2);
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
    int* arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int** dp = new int*[n];
    for(int i=0;i<n;i++){
        dp[i]= new int[n];
        for(int j=0;j<n;j++) dp[i][j]=-1;
    }
    int ans= solve(arr,n,0,n-1,dp);
    cout<<ans;
    return 0;
}