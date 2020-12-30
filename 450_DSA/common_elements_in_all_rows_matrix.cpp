#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define endl            '\n'
#define ff              first
#define ss              second
//#define int             long long
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

void solve(int** mat , int n ,int m){
    unordered_map<int,int > hash;
    for(int j=0;j<m;j++){
        hash[mat[0][j]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(hash[mat[i][j]]==i){
                hash[mat[i][j]]=1+i;

                if(hash[mat[i][j]]==m-1){
                    cout<<mat[i][j]<<" ";
                }
            }
        }
    }
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
        int n,m; cin>>n>>m;
        int **mat= new int*[n];
        for(int i=0;i<n;i++){
            mat[i]= new int[m];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        solve(mat,n,m);
    }
    return 0;
}