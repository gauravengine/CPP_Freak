#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define all(x) x.begin(),x.end()


#define MOD 1000000007
using namespace std;
using ll = long long;
vi init(string s)
{
  istringstream sin(s);
  int n;
  vi arr;
  while(sin>>n)arr.push_back(n);
  return arr;
}
// int dx[]={-1,1,0,0}; int dy[]={0,0,1,-1};
// int dx[]={2,2,-2,-2,1,1,-1,-1}; int dy[]={1,-1,1,-1,2,-2,2,-2};

/*------------------------------UNORDERED MAP HASH --------------------------------------------*/
//To make unordered_map unhackable 
// use it as unordered_map<int,int,custom_hash> mapp;
/*
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c 
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
*/
/*------------------------------END--------------------------------------------*/
inline int powMod(int a, int b) { int x = 1; while (b > 0) { if (b&1) x = (x*a) % MOD; a = (a*a) % MOD; b >>= 1; } return x; }
inline int multiply(int x, int y) { return ((x % MOD) * (y % MOD)) % MOD; }
inline int divide(int x, int y) { return ((x % MOD) * powMod(y % MOD, MOD-2)) % MOD; }
inline int ceil(int a, int b) { return (a+b-1)/b; }
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int inverseMod(int a, int m) { a = a % m; for (ll x = 1; x < m; x++) if ((a * x) % m == 1) return x; return -1; }

template<int D, typename T> struct vec : public vector<vec<D - 1, T>> { static_assert(D >= 1, "Vector dimension must be greater than zero!");  template<typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) { } }; template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, T val = T()) : vector<T>(n, val) { }};
int n,k;
bool check(int i,int j){
    return i>=0 && i<n && j>=0 && j<n;
}

int ans=-1;
int dx[2]={1,0};
int dy[2]={0,1};
vec<4,int> dp(151,151,2,300,INT_MIN);
int dfs(int i,int j,int bit,int rem,vec<2,bool> &valid,vec<2,int> mat){
    if(i==n-1 && j==n-1){
        if(valid[i][j]) return mat[i][j];
        else{
            // if(bit){
            //     if(rem>0) return mat[i][j];
            //     else return INT_MIN;
            // }
            if(rem>0) return mat[i][j];
            else return INT_MIN;
        }
    }
    if(dp[i][j][bit][rem]>INT_MIN) return dp[i][j][bit][rem];
    if(valid[i][j] && bit==0){
        int ans=mat[i][j];
        int op1=INT_MIN;
        for(int k=0;k<2;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(check(x,y)){
                op1=max(op1,dfs(x,y,0,rem,valid,mat));
            }
        }
        return dp[i][j][bit][rem]=ans+op1;
    }
    else if(bit==0 && !valid[i][j]){
        if(rem<=0) return INT_MIN;
        // or start from here
        int ans=mat[i][j];
        int op1=INT_MIN;
        rem--;
        bit=1;
        if(rem==0) bit=0;
        for(int k=0;k<2;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(check(x,y)){
                op1=max(op1,dfs(x,y,bit,rem,valid,mat));
            }
        }
        return dp[i][j][bit][rem]=ans+op1;
    }
    else{
        if(rem<=0) return INT_MIN;
        //continue
        int ans=mat[i][j];
        int op1=INT_MIN;
        rem--;
        bit=1;
        if(rem==0) bit=0;
        for(int k=0;k<2;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(check(x,y)){
                op1=max(op1,dfs(x,y,bit,rem,valid,mat));
            }
        }
        return dp[i][j][bit][rem]=ans+op1;
    }
}
void solve(){
    cin>>n>>k;
    ans=-1;
    vec<2,bool> valid (n,n,true);
    vec<2,int> mat(n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;
            cin>>x;
            if(x=='#') valid[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int fans=-1;
    fans=max(fans,dfs(0,0,0,k,valid,mat));
    cout<<fans<<"\n";
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
    int t=1;
    cin>>t;
    while(t--) solve();
    
    return 0;
}