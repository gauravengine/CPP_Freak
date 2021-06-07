#include <bits/stdc++.h>
using namespace std;

set<long long> S;

vector<long long> getDivisors(long long G)
{
    vector<long long> D;
    
    for (long long i=1; i*i<=G; i++)
        if (G % i == 0)
        {
            D.push_back(i);
            
            if (i * i != G)
                D.push_back(G / i);
        }
    
    sort (D.begin(), D.end());
    return D;
}

void func(long long a, long long b)
{
    if ((a + b - 1) % 2 || (a + b - 1) < 0)
        return;
    
    long long x = (a + b - 1) / 2;
    long long k = a - x;
    
    if (k <= 0 || k > a * b)
        return;
    
    S.insert(k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    
    int tests;
    cin >> tests;
    
    for (int test=1; test<=tests; test++)
    {
        cout << "Case #" << test << ": ";
        
        long long G;
        cin >> G;
        
        G *= 2;
        S.clear();
        
        int ans = 0;
        vector<long long> D = getDivisors(G);
        
        for (auto d : D)
            func(d, G / d);
        
        cout << S.size() << "\n";
    }
    
    return 0;
}
