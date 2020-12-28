#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
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

bool solve(unordered_map<int,int> &freq ,int *arr, int n,int k){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(k-arr[j]-arr[i] >0){
                freq[arr[i]]--;
                freq[arr[j]]--;
                if(freq[k-arr[i]-arr[j]] > 0) {
                    // db2(arr[i],arr[j]);
                    // cout << " k- arr[j] -arr[i] " << k - arr[j] - arr[i]<<endl;
                    return true;
                }
                else{
                    freq[arr[i]]++;
                    freq[arr[j]]++;
                }
            }
        }
    }
    return false;
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
        int n,k; cin>>n>>k;
        int *arr= new int[n];
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            freq[arr[i]]++;
        }
        bool ans= solve(freq,arr,n,k);
        if(ans) cout<<1;
        else cout<<0;
        delete [] arr;
        cout<<'\n';
    }
    return 0;
}