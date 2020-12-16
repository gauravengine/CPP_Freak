#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include<unordered_set>

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

int fact(int p){
    int output=1;
    for(int i=1;i<=p;i++){
        output= (output*i)%mod;
    }
    return output;
}

int bfs(int** &matrix, int n, int m,int i, int j){
    int ans=1;
    matrix[i][j]= 3;
    if(i-1 >=1 && j+2 <=m && matrix[i-1][j+2]==1) { ans += bfs(matrix, n,m , i-1,j+2); }
    if(i-1 >=1 && j-2 >=1 && matrix[i-1][j-2]==1) { ans += bfs(matrix,n,m,i-1,j-2) ; }
    if(i+1 <=n && j-2 >=1 && matrix[i+1][j-2]==1) ans += bfs(matrix, n,m,i+1,j-2);
    if(i+1 <=n && j+2 <=m && matrix[i+1][j+2] == 1) ans+= bfs(matrix,n,m,i+1,j+2);
    if(i+2 <=n && j-1 >=1 && matrix[i+2][j-1]==1) ans+= bfs(matrix,n,m,i+2,j-1);
    if(i+2 <=n && j+1 <=m && matrix[i+2][j+1]==1) ans+= bfs(matrix,n,m,i+2,j+1);
    if(i-2 >=1 && j+1 <=m && matrix[i-2][j+1]==1) ans += bfs(matrix,n,m,i-2,j+1);
    if(i-2 >=1 && j-1 >=1 && matrix[i-2][j-1]==1) ans += bfs(matrix,n,m,i-2,j-1);

    return ans;
}

void func(int** matrix , int n,int m){
    int ans=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i][j]==1){
                int x= bfs(matrix,n,m,i,j);
                ans = (ans* fact(x))%mod ;
            }
        }
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
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        int** matrix= new int*[n+1];
        for(int i=1;i<=n;i++){
            matrix[i]= new int[m+1];
            for(int j=1;j<=m;j++) matrix[i][j]=0;
        }
        for(int i=0;i<q;i++){
            int x,y; cin>>x>>y;
            matrix[x][y]= 1;
        }

        func(matrix,n,m);



        cout<<'\n';
    }
    return 0;
}