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

// void dfs(stack<int> &finishedVertex,unordered_set<int> &visited,vector<int>*edges,int current){
//     visited.insert(current);
//     for(int i=0;i<edges[current].size();i++){
//         int adjacent= edges[current][i];

//         if(visited.count(adjacent)==0){
//             db1(adjacent + 1);
//             dfs(finishedVertex,visited,edges,adjacent);
//         }
//     }
//     finishedVertex.push(current);
// }
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

unordered_set<int> *dfs2(vector<int> *edgesT, unordered_set<int> &visited, int current)
{
    visited.insert(current);
    unordered_set<int> *temp = new unordered_set<int>();
    temp->insert(current);
    unordered_set<int> *temp2 = new unordered_set<int>();
    for (int i = 0; i < edgesT[current].size(); i++)
    {
        int adjacent = edgesT[current][i];
        if (visited.count(adjacent) == 0)
        {
            temp2 = dfs2(edgesT, visited, adjacent);
        }
    }
    // unordered_set<int>::iterator it = temp2->begin();
    // while(it!= temp2->end()){
    //     temp->insert(*it);
    // }

    for (auto i : *temp2)
    {
        temp->insert(i);
    }
    // cout<<"printing temp"<<endl;
    // for (auto i : *temp)
    // {
    //     cout<<i+1;
    // }
    // cout<<endl;
    return temp;
}

unordered_set<unordered_set<int> *> *getScc(vector<int> *edges, vector<int> *edgesT, int v)
{
    unordered_set<int> visited;
    stack<int> finishedVertex;
    for (int i = 0; i < v; i++)
    {

        if (visited.count(i) == 0)
        {
            // db1(i+1);
            dfs(edges, visited, v, i, finishedVertex);
        }
    }
    stack<int> temp = finishedVertex;
    // cout << "printing stack "<<endl;
    // while (!temp.empty())
    // {
    //     int x = temp.top();
    //     temp.pop();
    //     cout << x + 1 << " ";
    // }
    // cout << endl;
    visited.clear();
    unordered_set<unordered_set<int> *> *output = new unordered_set<unordered_set<int> *>();
    while (!finishedVertex.empty())
    {
        int curr = finishedVertex.top();
        finishedVertex.pop();
        if (visited.count(curr) == 0)
        {
            unordered_set<int> *component = new unordered_set<int>();
            component = dfs2(edgesT, visited, curr);
            output->insert(component);
        }
    }

    return output;
}

int32_t main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    while (true)
    {
        int v;
        cin >> v;
        if (v == 0)
        {
            return 0;
        }
        int e;
        cin >> e;
        vector<int> *edges = new vector<int>[v];
        vector<int> *edgesT = new vector<int>[v];
        for (int i = 0; i < e; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            edges[v1 - 1].push_back(v2 - 1);
            edgesT[v2 - 1].push_back(v1 - 1); // bc i wrote edges here and wasted a lot of time in debugging fuckkkkkkkk
        }

        unordered_set<unordered_set<int> *> *components = getScc(edges, edgesT, v);
        // unordered_set<unordered_set<int> *>::iterator itf = components->begin();
        // cout<<"printing components"<<endl;
        // while (itf != components->end())
        // { //cout<<"here";
        //     unordered_set<int> *component = *itf;
        //     unordered_set<int>::iterator it2 = component->begin();
        //     while (it2 != component->end())
        //     {
        //         cout << *it2 + 1 << " ";
        //         it2++;
        //     }
        //     cout << endl;

        //     itf++;
        //     delete component;
        // }
        unordered_set<unordered_set<int> *>::iterator it = components->begin();
        vector<int> ans;
        while (it != components->end())
        {

            // check if this component is bottom or not if yes then print it else move to next one
            unordered_set<int>::iterator it2 = (*it)->begin();
            bool flag = true;
            //cout<<"here";
            while (it2 != (*it)->end())
            {
                int curr = *it2;
                //db1(curr+1);
                for (int i = 0; i < edges[curr].size(); i++)
                {
                    int adj = edges[curr][i];
                    //db1(adj+1);
                    if ((*it)->count(adj) == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
                it2++;
            }
            // db1(flag);
            if (flag)
            {
                // print this component in ascending order

                unordered_set<int>::iterator it2 = (*it)->begin();
                while (it2 != (*it)->end())
                {
                    ans.push_back(*it2 + 1);
                    it2++;
                }
            }
            it++;
        }

        sort(ans.begin(), ans.end());
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}