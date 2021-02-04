// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>


// #define db1(x) cout<<#x<<"="<<x<<'\n'
// #define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
// #define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
// #define ff              first
// #define endl            '\n'
// #define ss              second
// #define int             long long
// #define pb              push_back
// #define mp              make_pair
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define mii             map<int,int>
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int> >
// #define setbits(x)      __builtin_popcountll(x)
// #define zrobits(x)      __builtin_ctzll(x)
// #define mod             1000000007
// #define inf             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define w(x)            int x; cin>>x; while(x--)
// #define mod 1000000007
// using namespace std;
// using ll = long long;

// map<pii,int> dp;


// int solve(int* arr, int &n,int curr,int streak){

//     if(curr>=n) return 0;

//     pii key = mp(streak,curr);
//     if(dp.find(key)!= dp.end()) return dp.at(key);

//     if(streak==2){
//         return dp[key]=arr[curr] + solve(arr,n,curr+1,0);
//     }
//     else{
        
//         int op1=arr[curr] + solve(arr,n,curr+1,0);
//         int op2= solve(arr,n,curr+1, streak+1 );
//         return dp[key]=min(op1,op2);
//     }

//     return 0;

// }

// int32_t main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     //#ifndef ONLINE_JUDGE
//     //freopen("input.txt", "r", stdin);
//     //freopen("output.txt", "w", stdout);
//     //#endif 
//     int n; cin>>n;
//     int* arr= new int[n];

    

//     for(int i=0;i<n;i++) cin>>arr[i];
//     cout<<solve(arr,n,0,0);
//     // ok boomers if u have any questions post it on subreddit i may or may not check it in the next episode of laaatityy

//     return 0;
// }
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
    for(int i=0;i<n;i++) cin>>arr[i];
    int* dp = new int[n];
    dp[0]=arr[0];
    dp[1]=arr[1];
    dp[2]=arr[2];
    for(int i=3;i<n;i++){
        dp[i]= arr[i] + min(dp[i-1],min(dp[i-2],dp[i-3]));
    }

    int ans= min(dp[n-1],min(dp[n-2],dp[n-3]));
    cout<<ans;

    return 0;
}