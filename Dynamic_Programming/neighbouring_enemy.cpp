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
#define maxi 100005



int solve(int* arr, int curr, int n,vector<bool> isValid) {

	if (curr > n - 1) return 0;
	if (isValid[arr[curr]]) {
		db1(arr[curr]);
		isValid[arr[curr] - 1] = 0;
		isValid[arr[curr] + 1] = 0;
		int op1 = arr[curr] + solve(arr, curr + 1, n,isValid);
		isValid[arr[curr] - 1] = 1;
		isValid[arr[curr] + 1] = 1;
		int op2 = solve(arr, curr + 1, n,isValid);
		return max(op1, op2) ;
	}
	else {
		return solve(arr, curr + 1, n,isValid);
	}
	return 0;
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
	int n; cin >> n;
	int* arr = new int[n];
	vector<bool> isValid(maxi, true);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << solve(arr, 0, n,isValid);
	return 0;
}