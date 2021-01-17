// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// using these it wasnt accepting dunno why
#include "bits/stdc++.h"


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

int solve(int *arr, int n, int mid){
    int i= upper_bound(arr,arr+n,mid)-arr;
    int ans=0;
    for(;i<n;i++){
        ans += arr[i]-mid;
    }
    return ans;
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
    int n,m; cin>>n>>m;
    int *arr= new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int low= arr[0]; int high= arr[n-1];
    int ans;
    while(low<=high){
        int mid= low+(high-low)/2;
        int temp = solve(arr,n,mid); // gives the height of trees if saw was set at mid;
        if(temp>=m){
            ans= mid;
            //db1(ans);
            low=mid+1;
        }
        else{
            high= mid-1;    
        }
    }
    cout<<ans;
    return 0;
}