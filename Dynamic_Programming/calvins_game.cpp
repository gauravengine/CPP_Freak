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

//  int solve(int* arr,int curr,int bit,int n,int** dp){
//     //  bit 1 means i m still moving forward 0 means ive turned backwards and will not move forward
//     //db1(curr);
//     if(curr<1) return -1000000000;
//     if(curr>n) return 0;
//     if(curr==1){
//         return arr[1];
//     }

//     if(dp[bit][curr] !=-1) return dp[bit][curr];

//     if(bit==1){
//         // four moves
//        // db2("inside1",curr);
//         int opt1=arr[curr]+solve(arr,curr+1,1,n,dp);
//         int opt2=arr[curr]+solve(arr,curr+2,1,n,dp);
//         int opt3=arr[curr]+solve(arr,curr-1,0,n,dp);
//         int opt4=arr[curr]+solve(arr,curr-2,0,n,dp);
//         return dp[bit][curr]=max(max(opt1,opt2),max(opt3,opt4));

//     }
//     if(bit==0){
//         //db2("inside0",curr);
//         int opt3=arr[curr]+solve(arr,curr-1,0,n,dp);
//         int opt4=arr[curr]+solve(arr,curr-2,0,n,dp);
//         return dp[bit][curr]=max(opt3,opt4);
//     }
//     return 0;

// }

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k; cin >> n >> k;
    int *arr = new int[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) { //such idiot i am ;-)
        cin >> arr[i];
    }

    int *dpf = new int[n + 1];
    dpf[k + 1] = arr[k + 1];
    dpf[k + 2] = max( arr[k + 2], dpf[k + 1] + arr[k + 2] );
    for (int i = k + 3; i <= n; i++) {
        dpf[i] = arr[i] + max(dpf[i - 1], dpf[i - 2]);
    }
    int* dpb = new int[n + 1];
    dpb[0] = 0;
    dpb[1] = arr[1];
    dpb[2] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++) {
        dpb[i] = arr[i] + max(dpb[i - 1], dpb[i - 2]);
    }
    int ans = max(dpb[k - 1], dpb[k - 2]);
    for (int i = k + 1; i <= n; i++) {
        ans = max(ans, dpf[i] + dpb[i] - arr[i]);
    }
    cout << ans;
    // for(int i=0;i<2;i++){

    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    return 0;
}