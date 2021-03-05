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

bool check(string s){
	int n= s.length();
	int ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(') ans++;
		if(s[i]==')') ans--;
		if(ans < 0) return false;
	}
	if(ans !=0 ) return false;
	return true;
}

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	string s2 = s;
	string s3 = s;
	if (s[0] == s[n - 1]) {
		cout << "NO\n";
		return;
	}
	map<char,int> hash;
	hash[s[0]]=2;
	hash[s[n-1]]=1;

	for(int i=0;i<n;i++){
		if(hash[s2[i]]==1){
			s2[i]=')';
			//cout<<"h\n";
			//db1(s2);
		} 
		else if(hash[s2[i]]==2) {
			s2[i]='(';
			//cout<<"bk\n";
		}
		else if(hash[s2[i]]==0) {
			//db2(s2[i],hash[s2[i]]);
			s2[i]='(';
			//cout<<"ck\n";
		}
		//db1(s2);                                 
		if(hash[s3[i]]==1) s3[i]=')';
		else if(hash[s3[i]]==2) s3[i]='(';
		else if(hash[s3[i]]==0) s3[i]=')';
	}
	//db2(s2,s3);
	if(check(s2) || check(s3)){
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
	cin >> t;
	while (t--) solve();

	return 0;
}