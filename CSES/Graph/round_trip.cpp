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
#define MOD 1000000007
using namespace std;
using ll = long long;
inline int powMod(int a, int b) { int x = 1; while (b > 0) { if (b & 1) x = (x * a) % MOD; a = (a * a) % MOD; b >>= 1; } return x; }
inline int multiply(int x, int y) { return ((x % MOD) * (y % MOD)) % MOD; }
inline int divide(int x, int y) { return ((x % MOD) * powMod(y % MOD, MOD - 2)) % MOD; }
inline int ceil(int a, int b) { return (a + b - 1) / b; }
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int inverseMod(int a, int m) { a = a % m; for (ll x = 1; x < m; x++) if ((a * x) % m == 1) return x; return -1; }

template<int D, typename T> struct vec : public vector < vec < D - 1, T >> { static_assert(D >= 1, "Vector dimension must be greater than zero!");  template<typename... Args> vec(int n = 0, Args... args) : vector < vec < D - 1, T >> (n, vec < D - 1, T > (args...)) { } }; template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, T val = T()) : vector<T>(n, val) { }};
#define N 100004
vec<1, int> parent(N, -1);
vec<1, int> adj[N];
vec<1, bool> vis(N, false );
int sv = -1, ev = -1;

bool dfs(int curr, int par) {
  //db2(curr,par);
  vis[curr] = true;
  parent[curr] = par;
  for (auto &v : adj[curr]) {
    if (!vis[v]) {
      if (dfs(v, curr)) return true;
    }
    else if (par != v) {
      sv = curr;
      ev = v;
      return true;
    }
  }

  return false;
}

void solve() {
  //  int n,m;
  //  cin>>n>>m;
  // // db2(n,m);
  //  for(int i=0;i<m+1;i++){
  //   //db1(i);
  //   int a,b;
  //   cin>>a>>b;
  //   //db2(a,b);
  //   adj[a].push_back(b);
  //   adj[b].push_back(a);
  //   //cout<<"hola\n";
  //  }
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bool cycle = false;
  // cout<<"hola";
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (dfs(i, -1)) {
        cycle = true;

      }
    }
    if (cycle) break;
  }
  if (!cycle) {
    cout << "IMPOSSIBLE";
  } else {
    //print cycle
    vec<1, int> ans;
    int s = sv;
    while (sv != ev && sv != -1) {
      ans.push_back(sv);
      sv = parent[sv];
    }
    ans.push_back(ev);
    ans.push_back(s);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
  }
  return;
}

int32_t main()
{
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  //#ifndef ONLINE_JUDGE
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //#endif
  int t = 1;
  // cin>>t;
  while (t--) solve();

  return 0;
}
