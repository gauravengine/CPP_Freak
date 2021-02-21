#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define ff              first
//#define endl            '\n'
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

int getQuery(int l,int r){
    int x;
    cout<<"? "<<l<<" "<<r<<endl;
    // cout.flush();
    cin>>x;
    return x;
}

// ll bsearch(ll low, ll high)
// {

//     if (low >= high) {
//        return low;
//     }

//     ll mid = low + (high-low)/2;

//     int secondLargest=getQuery(low,high);


//     bool condition =  (secondLargest==getQuery(low,secondLargest))?  false : true;                   //test for set of 2 elements, no yes! if wrong, change mid

//     condition ? low = mid : high = mid-1 ;          // maintain the invariant [low,high)
//                             // other case, low = mid+1 : high = mid , invariant is (low,high]
//     return bsearch(low,high);
// }

void solve(){
	int n; cin>>n;
    int beg= 1,end=n;
while(beg<=end)
{
    if(beg== end ) break;
    int secondLargest= getQuery(beg,end);
    // check left
    if(end-beg ==1 && secondLargest==end){
        break;
    }
    else if(end-beg ==1 && secondLargest!=end){
        beg= end;
        break;
    }
    int ans;
    if(getQuery(beg,secondLargest)==secondLargest){
        //left it is
         end=secondLargest-1;
    }else{
         beg= secondLargest+1;
    }
}
    cout<<"! "<<beg<<endl;
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
    solve(); 
    
    return 0;
}