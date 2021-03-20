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

void print(int h, int s) {
	if (h < 10) cout << 0 << h;
	else cout << h;
	cout << ":";
	if (s < 10) cout << 0 << s;
	else cout << s;
	cout << "\n";
	return;
}

bool valid(int x, int limit) {

	set<int> s = {0, 1, 2, 5, 8};
	map<int, int> hash;
	hash[0] = 0;
	hash[1] = 1;
	hash[2] = 5;
	hash[5] = 2;
	hash[8] = 8;

	int time = 0;
	vector<int> t;
	int base = (x < 10) ? 1 : 0;
	while (x != 0) {
		int temp = x % 10;
		if (s.find(temp) == s.end()) return false;
		else {
			// time += hash[temp]*pow(10,base);
			// base++;
			t.push_back(temp);
		}
		x = x / 10;
	}
	//cout<<"hola";
	if (!t.empty()) {
		for (int i = t.size() - 1; i >= 0; i--) {
			time += hash[t[i]] * pow(10, base);
			base++;
		}
	}
	//db1(time);
	if (time < limit) return true;
	else return false;
}

void solve() {
	int h, m;
	cin >> h >> m;
	string t;
	cin >> t;
	int currh, currm;
	//int x=0;
	//while(t[x]!=':') x++;
	string temp1 = t.substr(0, 2);
	currh = stoi(temp1);
	string temp2 = t.substr(3, 2);
	currm = stoi(temp2);
	//db2(currh,currm);
	int ansh = -1;
	int ansm = -1;
	for (int i = currh; i < h; i++) {
		if (valid(i, m)) {
			//cout<<"yess";
			ansh = i;
			break;
		}
	}
	// if(ansh==0){
	// 	print(0,0);
	// 	return;
	// }
	if (ansh == -1) ansh = 0;
	
	if (ansh == currh ) {
		for (int i = currm; i < m; i++) {
			if (valid(i, h)) {
				ansm = i;
				break;
			}
		}
		//just change smthng here
		if (ansm == -1) {
			//need to update hour and min will be 0;
			ansh = -1;
			ansm = 0;
			for (int i = currh + 1; i < h; i++) {
				if (valid(i, m)) {
					//cout<<"yess";
					ansh = i;
					break;
				}
			}
			if (ansh == -1) ansh = 0;
			print(ansh, ansm);
			return ;
		}
	}
	else {
		// for (int i = 0; i < m; i++) {
		// 	if (valid(i, h)) {
		// 		ansm = i;
		// 		break;
		// 	}
		// }
		ansm=0;
	}
	print(ansh, ansm);
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