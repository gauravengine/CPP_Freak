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

void dfs(int i, int j, char** mat, int** visited, int n, int m) {
	//db2(i, j);
	if (visited[i][j]==1 ) return;
	else {
		//cout<<"hmm\n";
		visited[i][j]=1;

		int dx[] = { -1, 0, 0, 1};
		int dy[] = {0, -1, 1, 0};
		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];
			if (x < n && x >= 0 && y < m && y >= 0 && mat[x][y] == '.' && visited[x][y]==0) {
				//cout<<x<<" "<<y<<" hola \n";
				dfs(x, y, mat, visited, n, m);
			}
		}
	}
	return ;
}

void solve() {
	int n, m;
	cin >> n >> m;
	char** mat = new char*[n];
	for (int i = 0; i < n; i++) {
		mat[i] = new char[m];
		for (int j = 0; j < m; j++) cin >> mat[i][j];
	}

	int ans = 0;
	int** visited= new int*[n];
	for(int i=0;i<n;i++){
		visited[i]= new int[m];
		for(int j=0;j<m;j++){
			visited[i][j]=0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '.' && visited[i][j]==0 ) {
				//cout<<"hi\n";
				//cout << "printing vis\n";
				// for (auto i : visited) {
				// 	cout << i.first << " " << i.second << "\n";
				// }
				dfs(i, j, mat, visited, n, m);
				ans++;
			}
		}
	}
	//cout << "finding 3,5 in visited\n";
	// auto it = visited.find(mp(3, 5));
	// cout << (*it).first << " " << (*it).second << "\n";
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}