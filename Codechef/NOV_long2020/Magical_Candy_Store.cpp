#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
const unsigned int M = 1000000007;
typedef long long ll;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

ll solve(int baazi, ll *a, ll r, int n, ll i)
{
    ll c = ((i - 1) % n + 1);
    if (i == r)
    {
        return (a[c]%M);
    }
    // if(i==r){
    //     //  sari turn khatam even ho ya odd just return
    //     // make sure when defining dp to change turns
    //     if(baazi == 0){
    //         m[0] += a[c];
    //         return a[c];
    //     }
    //     else{
    //         m[1]+= a[c];
    //         return a[c];
    //     }

    // }
    ll ans = 0;
    if (i % n == 0)
    {
        // change baazi
        (baazi == 0) ? 1 : 0;
    }
    if (baazi == 1)
    {
        if (a[c] % 2 == 0)
        {
            ans = (a[c]%M + solve(baazi, a, r, n, i + 1)%M)%M;
        }
        else
        {
            ll opt1 = ((a[c] - 1)%M + solve(baazi, a, r, n, i + 1)%M )%M;
            ll opt2 = ((a[c])%M + solve(!baazi, a, r, n, i + 1)%M) %M;
            ans = max(opt1, opt2);
        }
    }
    //cout<<"here";
    return ans;
}
int main()
{
    fast_cin();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *a = new ll[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int q;
        cin >> q;
        // define dp here ?
        while (q--)
        {
           // cout << "here1";
            ll r;
            cin >> r;

            //  int baazi=1;  // 0 not for chef 1 for chef
            //unordered_map<int,ll> m; // for number of candies
            ll ans = solve(1, a, r, n, 1) % M;
            cout << ans << "\n";
        }
    }
    return 0;
}