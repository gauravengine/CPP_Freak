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

struct Interval
{
	int start, end;
};
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

void mergeIntervals(Interval arr[], int n, vec<1, pii> &newvect)
{
	// Test if the given set has at least one interval
	if (n <= 0)
		return;

	// Create an empty stack of intervals
	stack<Interval> s;

	// sort the intervals in increasing order of start time
	sort(arr, arr + n, compareInterval);

	// push the first interval to stack
	s.push(arr[0]);

	// Start from the next interval and merge if necessary
	for (int i = 1 ; i < n; i++)
	{
		// get interval from stack top
		Interval top = s.top();

		// if current interval is not overlapping with stack top,
		// push it to the stack
		if (top.end < arr[i].start)
			s.push(arr[i]);

		// Otherwise update the ending time of top if ending of current
		// interval is more
		else if (top.end < arr[i].end)
		{
			top.end = arr[i].end;
			s.pop();
			s.push(top);
		}
	}

	// Print contents of stack
	// cout << "\n The Merged Intervals are: ";
	while (!s.empty())
	{
		Interval t = s.top();
		//cout << "[" << t.start << "," << t.end << "] ";
		newvect.push_back({t.start, t.end});
		s.pop();
	}
	return;
}

int findNumber(vector<pair<int, int>>  a, int n, int K)
{

	int low = 0, high = n - 1;

	// Binary search
	while (low <= high) {

		// Find the mid element
		int mid = (low + high) >> 1;

		// If element is found
		if (K >= a[mid].first && K <= a[mid].second)
			return mid;

		// Check in first half
		else if (K < a[mid].first)
			high = mid - 1;

		// Check in second half
		else
			low = mid + 1;
	}

	// Not found
	return -1;
}
void solve() {
	int n; cin >> n;
	vec<1, bool> cake(n, false);
	vec<1, int> cream(n);
	vec<1, pii> vect;
	for (int i = 0; i < n; i++ ) cin >> cream[i];
	for (int i = 0; i < n; i++) {
		int j = i;
		int x = cream[i];
		// while(x>0 && j>=0){
		// 	cake[j]=true;
		// 	x--;
		// 	j--;
		// }
		int low = (j - x + 1 >= 0 ) ? j - x + 1 : 0;
		int high = j;
		if (low <= high) vect.push_back(mp(low, high));
	}
	sort(vect.begin(), vect.end());
	Interval arr[vect.size()];
	for (int i = 0; i < vect.size(); i++) {
		arr[i].start = vect[i].ff;
		arr[i].end = vect[i].ss;
	}

	vec<1, pii> newvect;
	mergeIntervals(arr, vect.size(), newvect);
	sort(newvect.begin(), newvect.end());
	// for (pair<int, int>& x : newvect)
	// cout << x.first << '\t' << x.second << endl;

	for (int i = 0; i < n; i++) {
		int key = i;
		//int key = 20;
		int j = findNumber(newvect, newvect.size(), key);
		if (j == -1) {
			cout << 0 << " ";
		} else {
			cout << 1 << " ";
		}
		// lower_bound uses a dichotomic search in log_2(N)

	}

	cout << "\n";
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
	while (t--) solve();

	return 0;
}