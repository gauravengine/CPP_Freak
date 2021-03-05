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

struct snuke
{
	int p,x;
	double a;
};

bool comparator(snuke t,snuke b){
	if(t.a == b.a) return t.p < b.p;
	return (t.a < b.a);
}

void solve(){
    int n; cin>>n;
    snuke ps[n];
    for(int i=0;i<n;i++){
    	cin>>ps[i].a>>ps[i].p>>ps[i].x;
    }
    sort(ps,ps+n,comparator);
    int ans=INT_MAX;
    //int time =0;
    for(int i=0;i<n;i++){
    	int tempsold = (ps[i].a+0.5);
    	int bache = ps[i].x- (tempsold/1);
    	//db1(bache);
    	if(bache >0) ans = min(ans,ps[i].p);
    }
    if(ans !=INT_MAX)cout<<ans;
    else cout <<-1;
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
    solve();
    
    return 0;
}