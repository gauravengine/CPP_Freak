#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <unordered_set>

#define db1(x) cout << #x << "=" << x << '\n'
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << '\n'
#define db3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << '\n'
#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

#define mod 1000000007

using namespace std;
using ll = long long;

void dfs(vector<int> *edges, unordered_set<int> &visited, int v, int start, stack<int> &finishedVertex)
{
    visited.insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        if (visited.count(edges[start][i]) == 0)
        {
            dfs(edges, visited, v, edges[start][i], finishedVertex);
        }
    }
    finishedVertex.push(start);
}
void dfs2(vector<int> *edges, int start, int v, unordered_set<int> &visited, unordered_set<int> *component)
{
    visited.insert(start);
    component->insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        if (visited.count(edges[start][i]) == 0)
        {
            dfs2(edges, edges[start][i], v, visited, component);
        }
    }
}

unordered_set<unordered_set<int> *> *getSCC(vector<int> *edges, vector<int> *edgesT, int v)
{
    unordered_set<int> visited;
    stack<int> finishedVertex;
    for (int i = 0; i < v; i++)
    {
        if (visited.count(i) == 0)
        {
            dfs(edges, visited, v, i, finishedVertex);
        }
    }
    
    // now my finishedVertex is filled so i have to start popping one by one
    unordered_set<unordered_set<int> *> *output = new unordered_set<unordered_set<int> *>();
    visited.clear();
    while (!finishedVertex.empty())
    {
        int i = finishedVertex.top();
        finishedVertex.pop();
        unordered_set<int> *component = new unordered_set<int>();
        if (visited.count(i) == 0)
        {
            dfs2(edges, i, v, visited, component);
            output->insert(component);
        }
    }

    return output;
}

int32_t
main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // cout.tie(0);
    int t; cin>>t;

    while(t--){
        int v;
        cin >> v;
        int e;
        cin >> e;
        vector<int> *edges = new vector<int>[v];
        vector<int> *edgesT = new vector<int>[v];
        for (int i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
            edgesT[y - 1].push_back(x - 1);
        }
        unordered_set<unordered_set<int> *> *components = new unordered_set<unordered_set<int> *>();
        components = getSCC(edges, edgesT, v);
        unordered_set<unordered_set<int> *>::iterator it = components->begin();
        int count = 0;
        while (it != components->end())
        { //cout<<"here";
            count++;
            it++;
        }
        cout << count << "\n";
        delete components;
        delete[] edges;
        delete[] edgesT;
    }
    
    return 0;
}