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
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int* arr= new int[n];
        for(int i=0;i<n;i++) cin>>arr[i];
     //    int reqsum=(n-1)*(n)/2;
    	// int sum=0,i=0;
    	// while(sum<reqsum && i<n){
    	// 	sum+=arr[i++];
    	// }
    	// bool flag2= (sum >= reqsum);
     //     bool flag= true;
     // 	 int count=0;
     //     for(int i=0;i<n;i++){
     //     	if(arr[i]<i) {
     //     		if(count==0){
     //     			count++;
     //     			continue;
     //     		}
     //     		flag= false;
     //     		break;
     //     	}
     //     }

    	// if(!flag || !flag2) cout<<"NO"<<endl;
    	// else cout<<"YES"<<'\n';
        bool flag= true;
        for(int i=0;i<n;i++){
        	if(arr[i]>=i){
        		if(i!=n-1) arr[i+1] += arr[i]-i;
        	}
        	else{
        		cout<<"NO"<<'\n';
        		flag = false;
        		break;
        	}
        }
        
        if(flag) cout<<"YES"<<'\n';
    }
    return 0;
}