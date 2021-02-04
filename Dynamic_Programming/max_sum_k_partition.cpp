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

int solve(int* arr,int n,int k){

    // call helper for not taking in this block
    int* dp=new int[n+1];
    dp[0]=0;
    int prev_max=0,prev_sec_max=0,prev_max_i=INT_MIN;
    for(int i=1;i<=n;i+=k){
       // db1(i);
        int curr_max=arr[i],curr_max_i=i,curr_sec_max=-1;
        for(int j=i;j<min(i+k,n+1);j++ ){
            if(arr[j]>curr_max){
                curr_max=arr[j];
                curr_max_i=j;
            }
            if(j-prev_max_i !=k)
                dp[j]=max(prev_max,curr_max+prev_max);
            else
                //db1(j);
                //cout<<"hhcurr max: "<<curr_max;
                dp[j]=max(prev_max, curr_max + prev_sec_max);
               // db1(dp[j]);
        }

        // change prev_max,prev_sec_max and prev_max_i
        prev_max=curr_max;
        prev_max_i=curr_max_i;
        for(int j=i;j<min(i+k,n+1);j++ ){
            if(j!=curr_max_i)
            {
                if(arr[j]>curr_sec_max||curr_sec_max==-1){
                curr_sec_max=arr[j];
                }
            }
            else continue;
        }
        prev_sec_max=curr_sec_max;
        // db1(prev_sec_max);
        // db1(prev_max_i);
        // db1(prev_max);
    }

    // for(int i=1;i<=n;i++) db2(i,dp[i]);
    return dp[n];
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
    int n,k; cin>>n>>k;
    int* arr= new int[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cout<<solve(arr,n,k);
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long> a(n);
    for(auto &i : a)
        cin >> i;
    long maxSum = 0;
    vector<long> dp = a;
    for(int i = k; i < n; i += k) {
        int max_i = i - k, smax_i = -1;
        for(int j = i - k + 1; j < i; j++) {
            if(dp[j] > dp[max_i]) {
                smax_i = max_i;
                max_i = j;
            }
            else if(smax_i == -1 or dp[j] > dp[smax_i]) {
                smax_i = j;
            }
        }
        for(int j = i; j < i + k and j < n; j++) {
			if(a[j] < 0) dp[j] = dp[max_i];
            else if(j - max_i != k) dp[j] = a[j] + dp[max_i];
            else dp[j] = a[j] + dp[smax_i];
            maxSum = max(maxSum, dp[j]);
        }
    }
    cout << maxSum;
}
*/