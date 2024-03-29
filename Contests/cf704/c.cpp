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

void print(int *arr,int size){
    cout<<" hola "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int n,m;
    cin>>n>>m;
    string s,t; cin>>s>>t;
    // from left sides
    int lefti[m];
    int righti[m];
    int si=0,ti=0;
    while(si<n && ti < m){
        if(s[si]==t[ti]){
            //db2(si,ti);
            lefti[ti]=si;
            si++;
            ti++;
        }
        else{
            si++;
        }
    }    

    //filling righti]
    si=n-1;ti=m-1;
    while(si >=0 && ti >=0){
        if(s[si]==t[ti]){
            righti[ti]=si;
            si--;
            ti--;
        }
        else{
            si--;
        }
    }
    // print(lefti,m);
    // print(righti,m);
    int ans= INT_MIN;
    for(int i=0;i<m-1;i++){
        ans = max(ans,righti[i+1]-lefti[i]);
    }

    cout<<ans;
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
     solve();
    
    return 0;
}