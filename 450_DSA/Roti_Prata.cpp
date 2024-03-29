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

bool solve(int *arr,int n, int mid,int p){
    // have to calculate whether p parathas are possible in mid time or not?
    int count=0;
    for(int i=0;i<n;i++){
        int r= arr[i]; // current halwai rank
        int x=1;
        int temp=x*r;
        while(temp <= mid){
            count++;
            x++;
            temp+= x*r;
        }

        if(count>=p) break;
    }
    if(count >= p) return true;
    else return false;

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
        int p,l; cin>>p>>l;
        
        // p parathas ordered l cooks available
        int *ranks= new int[l];
        for(int i=0;i<l;i++){
            cin>>ranks[i];
        }  
        sort(ranks,ranks+l);
        int low=0; int high= ranks[l-1]*((p)*(p+1)/2);
        //db1(high);
        int ans=0;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(solve(ranks,l,mid,p)){
                ans = mid;
                high=mid-1; // isse kam time me hoga kya ?
            }
            else {
                low= mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}