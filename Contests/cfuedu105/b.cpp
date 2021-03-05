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

void solve(){
    bool flag=true;
    int n,u,r,d,l;
    cin>>n>>u>>r>>d>>l;
    if(u==n-1){
    	if(d==n) flag&=(l>1 ||r>1)&&l>0&&r>0;
    	else if(d==n-1) flag&=(l+r>1);
    	else flag&=l+r>0;
    }else if(u==n){
    	if(d==n) flag&=l>1&&r>1;
    	else if(d==n-1) flag&=l+r>2&&l>0&&r>0;
    	else flag&=l>0&&r>0;
    }
    else if(d==n-1){
    	flag &=l+r>0;
    }else if(d==n){
    	flag&=l>0&&r>0;
    }

    if(r==n-1){
    	if(l==n) flag&=(u>1 ||d>1)&&u>0&&d>0;
    	else if(l==n-1) flag&=(u+d>1);
    	else flag&=u+d>0;
    }else if(r==n){
    	if(l==n) flag&=u>1&&d>1;
    	else if(l==n-1) flag&=u+d>2&&u>0&&d>0;
    	else flag&=u>0&&d>0;
    }
    else if(l==n-1){
    	flag &=u+d>0;
    }else if(l==n){
    	flag&=u>0&&d>0;
    }




	if(flag){
		cout<<"YES\n";

	}
	else{
		cout<<"NO\n";
	}
	return;
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
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}