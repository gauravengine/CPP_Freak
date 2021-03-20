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
inline int powMod(int a, int b) { int x = 1; while (b > 0) { if (b&1) x = (x*a) % MOD; a = (a*a) % MOD; b >>= 1; } return x; }
inline int multiply(int x, int y) { return ((x % MOD) * (y % MOD)) % MOD; }
inline int divide(int x, int y) { return ((x % MOD) * powMod(y % MOD, MOD-2)) % MOD; }
inline int ceil(int a, int b) { return (a+b-1)/b; }
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int inverseMod(int a, int m) { a = a % m; for (ll x = 1; x < m; x++) if ((a * x) % m == 1) return x; return -1; }

template<int D, typename T> struct vec : public vector<vec<D - 1, T>> { static_assert(D >= 1, "Vector dimension must be greater than zero!");  template<typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) { } }; template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, T val = T()) : vector<T>(n, val) { }};
int row,col;
bool check(int i,int j,vec<2,bool>& mat){
	//cout<<"hmm";
	//cout << mat[i][j]<<"\n";
	if(i>=0 && i<row && j>=0 && j<col && mat[i][j]){
		
		return true;
	}
	return false;
}

void solve(){
	int n,m; cin>>n>>m;
	row=n; col=m;
	vec<2,bool> mat(n,m,false),vis(n,m,false);
	pii start,end;	
	for(int i=0;i<n;i++){
		string s; cin>>s;
		//cout<<"inp string ";
		for(int j=0;j<m;j++){
			mat[i][j]= (s[j]!='#');
			if(s[j]=='A'){
				start.ff= i;
				start.ss=j;
			}
			if(s[j]=='B'){
				end.ff=i;
				end.ss=j;
			}
		}
	}
	// initialised the mat;
	queue<pii> q;
	q.push(start);
	vec<2,pii> prev(n,m);
	vis[start.ff][start.ss]=true;
	while(!q.empty()){
		pii temp= q.front();
		q.pop();
			if(temp==end) break;

		int dx[]={-1,0,0,1};
		int dy[]={0,-1,1,0};
		for(int k=0;k<4;k++){
			int x= temp.ff +dx[k];
			int y= temp.ss +dy[k];
			//db2(x,y);
			//cout<<"here mat[x][y] "<<mat[x][y]<<"\n";
			if(check(x,y,mat) &&!vis[x][y]){
				//db2(x,y);
				vis[x][y]=true;
				prev[x][y]=temp;
				q.push(mp(x,y));
			}
		}
	}
	prev[start.ff][start.ss]={-1,-1};
	if(vis[end.ff][end.ss] != true) {
		cout<<"NO";
		return ;
	}else{
		cout<<"YES\n";
		//find the path bc
		pii to=end;
		stringstream s;

		for(int i=prev[end.ff][end.ss].ff,j=prev[end.ff][end.ss].ss;i!=-1&& j!=-1;tie(i,j)=prev[i][j]){
			if(i-1 == to.ff && j==to.ss) s<<'U';
			else if(i+1==to.ff && j==to.ss) s<<'D';
			else if(i==to.ff && j+1==to.second) s<<'R';
			else if(i==to.ff && j-1==to.second) s<<'L';
			to={i,j};
		}
		string ans=s.str();
		reverse(ans.begin(),ans.end());
		cout<<ans.length()<<"\n";
		cout<<ans;
	}

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
    int t=1;
    //cin>>t;
    while(t--) solve();
    
    return 0;
}