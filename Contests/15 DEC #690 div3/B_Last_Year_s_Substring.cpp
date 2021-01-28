#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
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
        string s; cin>>s;
        bool flag=false;
        //cout<<s.back();
        if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[3]=='0' ) flag= true;
        if(s.back()=='0' && s[n-2]=='2'  && s[n-3]=='0' && s[n-4]=='2' )  flag=true; 
        // for(int i= 0;i<n-3;i++){
        //     if(s[i]=='2'){
        //         if(s[i+1]=='0'){
        //             if(s[i+2]=='2'){
        //                 if(s[i+3]='0') flag= true;
        //             }
        //         }
        //     }
        // }
        if(s[0]=='2' && s[1]=='0' && s.back()=='0' && s[n-2]=='2') flag= true;
        if (s[0] == '2' && s[1] == '0' && s.back() == '0' && s[2] == '2') flag= true;
        if (s[0] == '2' && s[n-3] == '0' && s[n - 2] == '2' && s.back() == '0') flag = true;
        
        //cout << s[0] << s[n - 3]<<s[n-2]<<s[s.length()-1]<<" "<<n-1;
        if (flag) cout << "YES";
        else cout<<"NO";
        
        cout << '\n';
    }
    return 0;
}