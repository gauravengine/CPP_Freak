#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define endl            '\n'
#define ff              first
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
        int n,x; cin>>n>>x;
        int *arr= new int[n];
        int sum=0;
        // bool flag= true;
        // for(int i=0;i<n;i++){
        //   cin>>arr[i];
        //   if(arr[i]%x!=0) flag= false;
        //   sum+= arr[i];  
        // } 
        // if(!flag || sum%x !=0){
        //     cout<<sum/x<<" "<<sum/x+1;
        // }
        // else{
        //     cout<<sum/x<<" "<<sum/x;
        // }
        int min=0,max=0;
        cin>>arr[0];
        sum+= arr[0];
        max += ceil(arr[0]/x*1.0);
        for(int i=1;i<n;i++){
            cin>>arr[i];
            max += ceil(1.0*arr[i]/x);
            sum+=arr[i];
            
          
        }
        cout<<ceil(1.0*sum/x)<<" "<<max;
        cout<<endl;

    }
    return 0;
}