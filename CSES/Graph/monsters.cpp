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



void solve() {
	int n, m; cin >> n >> m;

	vec<2, pii> parent(n, m, mp(-1, -1));
	queue<pair<pii, bool> > q;
	// true for char false for monster
	vec<2, bool> vis(n, m, false);
	vec<2, bool> mat(n, m);
	pii inicharpos;
	bool possible = false;
	vec<1, pii> monster;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			mat[i][j] = ( s[j] != '#' );
			if (s[j] == 'M') {
				vis[i][j] = true;
				q.push(mp(mp(i, j), false));
				//monster.push_back(mp(i,j));
			}
			else if (s[j] == 'A') {
				vis[i][j] = true;
				inicharpos.ff = i;
				inicharpos.ss = j;
			}
		}
	}
	int dx[] = { -1, 0, 0, 1};
	int dy[] = {0, -1, 1, 0};
	int x = inicharpos.ff;
	int y = inicharpos.ss;
	if ( (x == n - 1 || x == 0 || y == 0 || y == m - 1) ) {
		cout<<"YES\n";
		cout<<0;
		return;
	}
	//db2(inicharpos.ff,inicharpos.ss);
	auto check = [&](int i, int j) {
		return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] && !vis[i][j]);
	};
	q.push(mp(inicharpos, true));
	pii end;
	// for(int m=0 ;m<monster.size(); m++){
	// 	q.push(mp(monster[m],false));
	// }
	while (!q.empty()) {
		if (possible) break;
		auto curr = q.front();
		q.pop();
		vis[curr.ff.ff][curr.ff.ss] = true;
		//db3(curr.ff.ff,curr.ff.ss,curr.ss);
		for (int k = 0; k < 4; k++) {
			int x = curr.ff.ff + dx[k];
			int y = curr.ff.ss + dy[k];
			if (check(x, y)) {
				vis[x][y] = true;
				q.push(mp(mp(x, y), curr.ss));
				parent[x][y] = mp(curr.ff.ff, curr.ff.ss);
				if ( (x == n - 1 || x == 0 || y == 0 || y == m - 1) && (curr.ss)) {
					possible = true;
					end.ff = x;
					end.ss = y;
					//db2(curr.ff.ff,curr.ff.ss);
					//db2(x, y);
				}
			}

		}
	}
	if (!possible) {
		cout << "NO";

	} else {
		cout << "YES\n";
		//find the path bc
		pii to = end;
		stringstream s;

		for (int i = parent[end.ff][end.ss].ff, j = parent[end.ff][end.ss].ss; i != -1 && j != -1; tie(i, j) = parent[i][j]) {
			if (i - 1 == to.ff && j == to.ss) s << 'U';
			else if (i + 1 == to.ff && j == to.ss) s << 'D';
			else if (i == to.ff && j + 1 == to.second) s << 'R';
			else if (i == to.ff && j - 1 == to.second) s << 'L';
			to = {i, j};
		}
		string ans = s.str();
		reverse(ans.begin(), ans.end());
		cout << ans.length() << "\n";
		cout << ans;
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
	int t = 1;
	// cin>>t;
	while (t--) solve();

	return 0;
}