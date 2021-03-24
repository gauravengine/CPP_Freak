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

bool check(int i, int j, int r, int c, int** mat) {
    if (i >= 0 && i < r && j >= 0 && j < c && mat[i][j] == 1) return true;
    else return false;
}


map<pii, int> mapp;

int helper(int** mat, map<pii, int[4] > &dp, int x, int y, int dx, int dy, int r, int c) {
    if (!check(x, y, r, c, mat)) return 0;
    //implement dp
    pii key = mp(x, y);
    int ind = mapp[mp(dx, dy)];

    if (dp.find(key) != dp.end()) {

        //
        // if(x==2) {
        //     db2(x,y);
        //     db2(ind,dp[key][ind]);
        // }
        if (dp[key][ind] != 0)
            return dp[key][ind];
    }
    x = x + dx;
    y = y + dy;
    dp[key][ind] = ( (1 + helper(mat, dp, x, y, dx, dy, r, c)) );
    int temp = dp[key][ind];
    //db1(temp);
    return temp;

}

void rec(int big, int small, int &ans) {
    if (big < 2 || small < 2) return ;
    //if(big<=small) return;
    while (small >= 2) {
        if (big >= small * 2) ans++;
        small--;
    }
    // swap(big, small);
    // while (small >= 2) {
    //     if (big >= small * 2) ans++;
    //     small--;
    // }
    return ;
}

void filldp(int** mat, int r, int c, map<pii, int[4] > &dp, int &ans) {
    //pii key= make_pair(i,j);
    //if(dp.find(key) != dp.end()) return;
    // r d l u
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 1) {
                pii key = mp(i, j);
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    int ind = mapp[mp(dx[k], dy[k])];
                    dp[key][ind] = (1 + helper(mat, dp, x, y, dx[k], dy[k], r, c));
                }
            }
        }
    }
    // print dp
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         if (mat[i][j] == 1) {
    //             pii key = mp(i, j);
    //             int r = dp[key][0];
    //             int d = dp[key][1];
    //             int l = dp[key][2];
    //             int u = dp[key][3];
    //             db2(i, j);
    //             cout << "r " << r << " d " << d << " l " << l << " u " << u << '\n';
    //         }
    //     }
    // }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 1) {
                pii key = mp(i, j);
                int r = dp[key][0];
                int d = dp[key][1];
                int l = dp[key][2];
                int u = dp[key][3];
                int big = d;
                int small = l;
                rec(big, small,  ans);
                small = r;
                rec(big, small, ans);
                big = u;
                small = l;
                rec(big, small, ans);
                small = r;
                rec(big, small, ans);
                big = l;
                small = u;
                rec(big, small, ans);
                small = d;
                rec(big, small, ans);
                big = r;
                small = u;
                rec(big, small, ans);
                small = d;
                rec(big, small, ans);
                //db1(ans);

            }
        }
    }

}

void solve(int caseno) {
    int ans = 0;
    int r, c;
    cin >> r >> c;
    int** mat = new int*[r];
    for (int i = 0; i < r; i++) {
        mat[i] = new int[c];
    }
    //taking input
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    map<pii, int[4] > dp;
    filldp(mat, r, c, dp, ans);

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
    mapp[ {0, 1}] = 0;
    mapp[ {1, 0}] = 1;
    mapp[ {0, -1}] = 2;
    mapp[ { -1, 0}] = 3;
    while (t--) {
        solve(i);
        i++;
    }
    return 0;
}