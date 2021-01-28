// Created by yadav_gaurav
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
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
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v;
        int a; cin >> a; v.push_back(a);
        unordered_map<int, int> freq; freq[v[0]]++;
        for (int i = 1; i < n; i++) {
            int a; cin >> a;
            if (a == v.back()) {
                continue;
            }
            else {
                freq[a]++;
                v.push_back(a);
            }
        }
        // now the vector is free from consecutives
        if (freq[v[0]] == v.size()) {
            cout << 0;
        }
        else {
            freq[v[0]]--;
            freq[v[v.size() - 1]]--;
            int ans = freq[v[0]] + 1;
            for (int i = 1; i < v.size(); i++) {
                if (ans > freq[v[i]] + 1) {
                    ans = freq[v[i]] + 1;
                }
            }
            cout << ans;
        }

        cout << '\n';
    }
    return 0;
}