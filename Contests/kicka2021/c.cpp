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


void solve(int caseno) {
    int ans = 0;
    int r, c;
    cin >> r >> c;
    vec<2, int> mat(r, c);
    //priority_queue< int > pq;
    set<pair<int,pii>> pq;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
            pq.insert(mp(-mat[i][j], mp(i, j)));
        }
    }
    vec<2, bool> vis(r, c, false);
    auto check = [&](int i, int j) { return (i >= 0 && i < r && j >= 0 && j < c  && !vis[i][j]); };

    while (!pq.empty()) {
        auto curr = *(pq.begin());
        //pq.begin() points to first pair and *pq.begin is the first pair
        pq.erase(pq.begin());
        int i = curr.ss.ff;
        int j = curr.ss.ss;
        //db2(i,j);
        if (vis[i][j]) continue;
        vis[i][j] = true;
        int dx[4] = { -1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            //oof never cheacked if x and y are ok !!!!!!!
            if (check(x, y)) {
                if (vis[x][y]) continue;
                else {
                    if (abs(mat[i][j] - mat[x][y]) > 1) {
                        //change
                        //mat[x][j] has to be low tho otherwise it had come first
                        ans += mat[i][j] - mat[x][y] - 1;
                        mat[x][y] = mat[i][j] - 1;
                        pq.insert(mp(-mat[x][y], mp(x, y)));
                        //db3(x,y,ans);
                    }
                }
            }

        }
    }
    cout << "Case #" << caseno << ": " << ans << '\n';
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
    int t = 1;
    cin >> t;
    int i = 1;
    while (t--) {
        solve(i);
        i++;
    }
    return 0;
}