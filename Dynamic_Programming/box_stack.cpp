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
inline int ceil(i
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int inverseMod(int a, int m) { a = a % m; for (ll x = 1; x < m; x++) if ((a * x) % m == 1) return x; return -1; }

template<int D, typename T> struct vec : public vector<vec<D - 1, T>> { static_assert(D >= 1, "Vector dimension must be greater than zero!");  template<typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) { } }; template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, T val = T()) : vector<T>(n, val) { }};
struct box
{
	int l=0,b=0,h=0;
};
bool comp( struct box  &a,struct box &c){
	// if(a.l==c.l ){
	// 	return a.b>c.b; 
	// }
	// else if( a.b== c.b){
	// 	return a.l>c.l;
	// }
	//return a.l > c.l && a.b > c.b;
	return a.l*a.b > c.l*c.b;
}

bool check(struct box &a,struct box &c){
	return a.l > c.l && a.b > c.b;
}
void solve(){
    int n;cin>>n;
    box arr[6*n];
    for(int i=0;i<6*n;i+=6){
    	int l,b,h;
    	cin>>l>>b>>h;
    	arr[i+0].l=l , arr[i+0].b=b , arr[i+0].h=h;
    	arr[i+1].l=b , arr[i+1].b=l , arr[i+1].h=h;
    	arr[i+2].l=b , arr[i+2].b=h , arr[i+2].h=l;
    	arr[i+3].l=h , arr[i+3].b=b , arr[i+3].h=l;
    	arr[i+4].l=l , arr[i+4].b=h , arr[i+4].h=b;
    	arr[i+5].l=h , arr[i+5].b=l , arr[i+5].h=b;
    	    
    }
    sort(arr,arr+6*n,comp);
    for(int i=0;i<6*n;i++){
    	cout<<"l : "<<arr[i].l<<" b : "<<arr[i].b<<" h : "<<arr[i].h<<'\n';
    }
    //dp[i] is the highest hight by using ith box
    vector<int> dp(6*n);
    for(int i=0;i<6*n;i++){
    	dp[i]=arr[i].h;	
    	for(int j=0;j<i;j++){
    		if(check(arr[j],arr[i])){
    			// i can put i over j it means
    			dp[i]= max(dp[i],arr[i].h + dp[j]);
    		}
    	}
    }
    // cout<<"printing dp array :\n";
    // for(int i=0;i<dp.size();i++){
    // 	cout<<dp[i]<<" ";
    // }
    int ans=dp[0];
    for(int i=0;i<dp.size();i++){
    	ans=max(ans,dp[i]);		
    }
    cout<<ans<<'\n';
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
    cin>>t;
    while(t--) solve();
    
    return 0;
}