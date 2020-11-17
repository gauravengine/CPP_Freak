#include<iostream>
#include<queue>
using namespace std;
bool haspath(int **edges,int v,bool* visited,int from,int to)
{	if(edges[from][to]==1) return true;
	if(from==to) return true;
	visited[from]=true;
	for(int i=0;i<v;i++){
		if(from==i) continue;
		if(!visited[i] && edges[i][from]==1){
			visited[i]=true;
			if(haspath(edges,v,visited,i,to)) return true;
			else continue;
		}
	}
	return false;
}

int main(){
		int v,e;
	cin>>v>>e;
	int** edges= new int *[v];
	
	for(int i=0;i<v;i++){
		edges[i]= new int[v];
		for(int j=0;j<v;j++){
			edges[i][j]=0;
		}
	}

	for (int i = 0; i < e; ++i)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	int from ,to;
	cin>>from>>to;
	bool *visited= new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}

	if(haspath(edges, v, visited,from ,to)) cout<<"true";
	else cout<<"false";


	return 0;
}