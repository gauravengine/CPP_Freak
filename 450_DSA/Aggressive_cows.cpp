// done
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

bool solve(int *arr,int n, int mid, int c){
    int c_count=1;
    int last_cow=0;
    // 1 2 4 8 9
    for(int i=1;i<n;i++){
        if(arr[i]-arr[last_cow]>=mid){
            last_cow= i;
            c_count++;
        }
        if(c_count>=c) break;
    }
    if(c_count >= c) return true;
    else return false;
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
    int t;
    cin>>t;
    while(t--){
        int n; int c;
        cin>>n>>c;
        int *arr= new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        // 1 2 4 8 9
        int low= arr[0], high= arr[n-1];
        int ans;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(solve(arr,n,mid,c)){
                ans= mid;
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}