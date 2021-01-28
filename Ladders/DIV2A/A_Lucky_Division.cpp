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

bool lucky(int n){
    //cout<<"hola";
    while(n>=1){
        if(n%10 !=4 && n%10 !=7 ){
            //db1(n%10);
            return false;
        }
        n=n/10;
       // db1(n);
    }
    return true;
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
    int n; cin>>n;
    // if(lucky(n)){
    //     cout<<"YES";
    // }
    // while(n>1){
    //     if(lucky(n)){
    //         flag = true;
    //         break;
    //     }
    //     else{
    //     }
    // }

    for(int i=1;i<=n;i++){
        if(lucky(i)){
            if(n%i==0){
                //db1(i);
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";

    return 0;
}