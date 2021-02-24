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

inline void helper(vector<int> &arr,int start,int &endptr){
	//int n= arr.size();
	for(int i=start;i<=endptr;i++){
		cout<<arr[i]<<" ";
	}
	//arr.erase(arr.begin()+start,arr.end());
	//ansptr += (n-1-start +1);
	return;
}

inline int maxhelper(vector<int> &arr,int endptr){
	int max=-1 ,pos=-1;
	for(int i=endptr;i>=0;i--){
		if(max< arr[i] ){
			max=arr[i];
			pos= i;
		}
	}
	return pos;
}

// inline void print ( vector<int> &ans){
// 	for(int i=0;i<ans.size();i++){
// 		cout<<ans[i]<<" ";
// 	}
// 	cout<<"\n";
// 	return;
// }

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    //vector<int> ans;
    int endptr=n-1;
    while(endptr >=0){
	    int maxpos= maxhelper(arr,endptr);
	   // db1(maxpos);
	   	helper(arr,maxpos,endptr);
	   	endptr = maxpos-1;
    }
    cout<<'\n';

    //print(ans);
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
    //cout<<'\n';
    return 0;
}