#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include<unordered_map>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define endl            '\n'
#define ff              first
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

 
#define MAX 100000
#define mod 1000000007

using namespace std;
using ll = long long;
int** dp = new int*[2*MAX];

int solve(int *h,int k1,int k2,int i,int n,int** dp){
    // base cases
    //db1(i);
    // if(k1<0) {
    //     db2(k1,k2);
    //     k1=0;
    // }
    // if(k2<0){
    //     db2(k1,k2);
    //     k2=0;
    // } 
    if(i==n) {
        if(k1<=0 && k2<=0){
            return 0;
        }else{
            return 1e9;
        }
        
    }
    //db2(k1,k2);
    
    if(k1<=0 && k2 <=0) return 0;

    if(dp[k1+MAX][k2+MAX] >-1) return dp[k1+MAX][k2+MAX];
    if(dp[k2+MAX][k1+MAX] >-1) return dp[k2+MAX][k1+MAX];
    int opt1,opt2; //opt3=1e9,opt4=1e9;
    if(k1>0){
       
        opt1= 1+ solve(h,k1-h[i],k2,i+1,n,dp);
        //opt2= solve(h,k1,k2,i+1,n,dp);
    }
    if(k2>0){
        opt2= 1+ solve(h,k1,k2-h[i],i+1,n,dp);
        //opt4= solve(h,k1,k2,i+1,n,dp);
    }
    dp[k2+MAX][k1+MAX] =min(opt1,opt2);
    
    
    return dp[k1+MAX][k2+MAX] =min(opt1,opt2);;

}
void print(int**dp,int k){
    for(int i=0;i<=k;i++){    
        for(int j=0;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
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
    while(t--){
        int n,k; cin>>n>>k;
        int *h= new int[n];
        int sum=0;
        for(int i=0;i<n;i++) {
            cin>>h[i];
            sum+=h[i];
        }
        if(sum < 2*k || n==1) {
            cout<<-1<<endl;
            continue;
        }
       // int** dp = new int*[2*MAX];
        for(int i=0;i<2*MAX;i++){
            dp[i]= new int[2*MAX];
            for(int j=0;j<2*MAX;j++){
                dp[i][j]=-1;
            }
        }
        sort(h,h+n,greater<int>());
        int ans= solve(h,k,k,0,n,dp);
        //print(dp,k);
        if(ans >=1e9 || ans==-1) cout<<-1<<endl;
        else cout<<ans<<"\n";
    }
    return 0;
}