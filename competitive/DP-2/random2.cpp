#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
const ll N = 200005;
char en = '\n';
ll inf = 2e16;
ll mod = 1e9 + 7;
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
	if (n & 1)
	  res = (res * x) % mod;
	x = (x * x) % mod;
	n >>= 1;
  }
  return res;
}


void update(string &a, vector<ll> op) {
  char c = 'z';
  for (ll &x : op)
	c = min(c, a[x]);
  for (ll &x : op)
	a[x] = c;
}

vector<vector<ll>> res;
ll solve(string a, string b, ll n) {
  vector<int> indices[30];
  for (int i = 0; i < n; i++)
	indices[b[i] - 'a'].emplace_back(i);

  bool visited[n + 5];
  memset(visited, false, sizeof(visited));

  for (int i = 25; i >= 0; i--) {

	if (indices[i].empty())
	  continue;

	vector<ll> curr;

	for (ll j = 0; j < n; j++) {
	  if (!visited[j] && (a[j] - 'a') >= i)
	    curr.emplace_back(j);
	}

	bool good = true;
	for (int &x : indices[i]) {
	  visited[x] = true;
	  if ((a[x] - 'a') != i) {
	    good = false;
	  }
	}

	if (good)
	  continue;
	update(a, curr);

	res.emplace_back(curr);
  }

  if (a != b) {
	return -1;
  }
  return res.size();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;

  while (t--) {
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	res.clear();
	ll val = solve(a, b, n);
	if (val == -1) {
	  cout << -1 << en;
	  continue;
	}

	cout << res.size() << en;
	for (vector<ll> &x : res) {
	  cout << x.size() << " ";
	  for (ll &y : x)
	    cout << y << " ";
	  cout << en;
	}
  }
  return 0;
}