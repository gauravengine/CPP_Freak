#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> gp[100010];
map<ll, map<ll, ll>> m;
int color[100010];
ll n,q;
bool isBipartiteUtil(ll src)
{
    color[src] = 1;
    queue<ll> q;
    q.push(src);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (int v = 0; v < gp[u].size(); ++v)
        {
            int vv = gp[u][v];
            int c = m[u][vv];
            if (color[vv] == -1)
            {
                if (c == 0)
                    color[vv] = color[u];
                else
                    color[vv] = 1 - color[u];
                q.push(gp[u][v]);
            }
            else if (abs(color[gp[u][v]] - color[u]) != c)
                return false;
        }
    }
    return true;
}
bool isBipartite()
{
    for (int i = 0; i <= n; ++i)
        color[i] = -1;
    for (int i = 1; i <= n; i++)
        if (color[i] == -1 && gp[i].size() >= 1)
            if (isBipartiteUtil(i) == false)
                return false;
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        m.clear();
        
        cin >> n >> q;
        bool ans = true;
        for (int i = 0; i < n; i++)
            gp[i].clear();
        while (q--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            gp[a].push_back(b);
            gp[b].push_back(a);
            if (m.find(a) != m.end() && m[a].find(b) != m[a].end())
            {
                if (m[a][b] != c)
                    ans = false;
            }
            else if (m.find(b) != m.end() && m[b].find(a) != m[b].end())
            {
                if (m[b][a] != c)
                    ans = false;
            }
            else
            {
                m[a][b] = m[b][a] = c;
            }
        }

        if (!ans)
        {
            cout << "no" << endl;
            continue;
        }
        ans = isBipartite();
        if (ans == false)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
    return 0;
}