#include<bits/stdc++.h> 
using namespace std; 
  


void printGraph(vector<int> adj[], int V) 
{ 
    for (int v = 0; v < V; ++v) 
    { 
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
    } 
} 
  

int main() 
{ 
    int V = 5; 
    vector<int> adj[V]; 
    cout<<"enter no of edges :"; 
    int e;
    cin>>e;
    for (int i = 0; i < e; i++)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    printGraph(adj, V); 
    return 0; 
} 