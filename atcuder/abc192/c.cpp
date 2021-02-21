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
//#define int             long long
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

int g1(int x){
	// desc
	vector<int> temp;
	while(x>0){
		temp.push_back(x%10);
		x = x/10;
	}
	sort(temp.begin(),temp.end(),greater<int>());
	int ans1=0;
	int size= temp.size();
	int tenpow=0;
	// db1(pow(10,0));
	for(int i=size-1;i>=0;i--){
		//db1(temp[i]);
		int a=pow(10,tenpow);
		ans1+= temp[i]*a;
		tenpow++;
	}
	int ans2=0;

	tenpow=0;
	for(int i=0;i<temp.size();i++){
		//db1(temp[i]);
		int a=pow(10,tenpow);
		ans2+= temp[i]*a;
		tenpow++;
	}
	return ans1-ans2;
}

// int g2(int x){
// 	//asc
// 	vector<int> temp;
// 	while(x>0){
// 		temp.push_back(x%10);
// 		x = x/10;
// 	}
// 	sort(temp.begin(),temp.end());
// 	int ans=0;
// 	int size= temp.size();
// 	int tenpow=0;
// 	for(int i=size-1;i>=0;i--){
// 		ans+= temp[i]*pow(10,tenpow);
// 		tenpow++;
// 	}
// 	return ans;
// }

void solve(){
    int n,k; cin>>n>>k;
    //ak
    int b=n;
    //db2(g1(n),g2(n));
    for(int i=1;i<=k;i++){
    	b= g1(n);
    	n=b;
    	if(b==0 && n==0 ) break;
    	//db2(b,n);
    }

    cout<<b;
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