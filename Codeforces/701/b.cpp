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
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif  
    int n,q,k;
    cin>>n>>q>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    while(q--){
    	int l,r;
    	cin>>l>>r;
    	l--,r--;
    	if(l==r){
    		cout<<k-1<<endl;
    		continue;
    	}
    	int ans=0;
    	// for(int i=l;i<=r;i++){
    	// 	if(i==l){
    	// 		//just check arr[i+1]
    	// 		if(arr[i+1]-2>0 && i+1<=r){
    	// 			ans+= (arr[i+1]-2);
    	// 		}
    	// 	}
    	// 	else if(i<r){
    	// 		int temp= arr[i+1]-arr[i-1]-2;
    	// 		if(temp>0){
    	// 			ans+=temp;
    	// 		}
    	// 	}
    	// 	else{
    	// 		int temp= k-arr[i-1]-1;
    	// 		if(temp>0) ans+= temp;
    	// 	}
    	// 	//db1(ans);
    	// }
    	ans=k+arr[r]-arr[l]-1-2*(r-l);
    	cout<<ans<<'\n';
    }

    return 0;
}