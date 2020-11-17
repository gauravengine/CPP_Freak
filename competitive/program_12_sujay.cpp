#include<iostream> 
#include <list> 
using namespace std; 
class Graph 
{ 
int V; 
list<int> *adj; 
void printAllPathsUtil(int , int , bool [], int [], int &); 
public: 
Graph(int V); 
void addEdge(int u, int v); 
void printAllPaths(int s, int d); 
bool isCyclic(); 
bool isCyclicUtil(int,bool [],bool *); 
 
}; 
Graph::Graph(int V) 
{ 
this->V = V; 
adj = new list<int>[V]; 
} 
void Graph::addEdge(int u, int v) 
{ 
adj[u].push_back(v); 
} 
void Graph::printAllPaths(int s, int d) 
{ 
bool *visited = new bool[V]; 
int *path = new int[V]; 
int path_index = 0; 
for (int i = 0; i < V; i++) 
visited[i] = false; 
printAllPathsUtil(s, d, visited, path, path_index); 
} 
void Graph::printAllPathsUtil(int u, int d, bool visited[], int path[], int &path_index) 
{ 
visited[u] = true; 
path[path_index] = u; 
path_index++; 
if (u == d) 
{ 
for (int i = 0; i<path_index; i++) 
cout << path[i] << "->"; 
cout << endl; 
} 
else 
{ 
list<int>::iterator i; 
for (i = adj[u].begin(); i != adj[u].end(); ++i) 
if (!visited[*i]) 
printAllPathsUtil(*i, d, visited, path, path_index); 
} 
path_index--; 
visited[u] = false; 
} 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        visited[v] = true; 
        recStack[v] = true; 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
 
    } 
    recStack[v] = false; 
    return false; 
} 
bool Graph::isCyclic() 
{ 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
 
    return false; 
} 
int main() 
{ 
cout<<"MADE BY GAURAV     2019UCO1652    COE-2"<<endl; 
int n,x,y,s,d; 
Graph G(10); 
cout<<"Enter number of edges for a graph:"; 
cin>>n; 
for(int i=1 ; i<=n ; i++) 
{ 
cout<<"Enter the value of "<<i<<"th vertex in pair (x,y):\n"; 
cin>>x>>y; 
G.addEdge(x , y); 
} 
if(G.isCyclic()) 
    cout<<"Graph is Cyclic\n"; 
else 
    cout<<"Graph is not Cyclic\n"; 
cout<<"Enter Source and Destination:\n"; 
cin>>s>>d; 
cout << "Following are all different paths from " << s << " to " << d <<":\n"; 
G.printAllPaths(s, d); 
return 0; 
}
