//bc ni hora ye kal dekhunga
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
    int n; cin>>n;
    int* arr= new int[n];
    int hash[n+1];
    int sum=0;
    hash[0]=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        hash[i+1]=sum;
    }
    sort(arr,arr+n);
    int q; cin>>q;
    while(q--)
    {
        int a; cin>>a;
        int i=upper_bound(arr,arr+n,a)-arr;
        
        // if(i!= n &&arr[i]==a ){
        //     cout<<i+1<<" "<<hash[i]<<endl;
        // }
        // else if(i==n){
        //     cout<<i<<" "<<hash[i-1]<<endl;
        // }
        // else if(arr[i]!= a && i!=0){
        //     cout<<i<<" "<<hash[i-1]<<endl;
        // }else{
        //     // i==0
        //     cout<<0<<" "<<0<<endl;
        // }

        cout<<i<<" "<<hash[i]<<endl;
    }
    return 0;
}