#include<iostream>
#include<queue>
#include<map>
using namespace std;

void path_bfs(int** edges,int v,bool* visited,int from ,int to){
	map<int,int> m;
	queue<int> q;
	bool flag=false;
	visited[from]=true;
	q.push(from);
	while(!q.empty()){
		int sv=q.front();
		for(int i=0;i<v;i++){
			if(i==sv) continue;
			if(visited[i]==false && edges[i][sv]== 1){
				q.push(i);
				visited[i]=true;
				m[i] = sv;
				if(i==to){
					flag=true;
				 break;
				}
		
			}
		
		}
		
		q.pop();

	}
	if(from ==to ) cout<<from;
	
	if(flag){
	
		cout<<to<<" ";
		int x=m[to];
		while( x != from){
			cout<<x<<" ";
			x=m[x];
		}
		cout<<from;
	}
	
	return; 
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

	
	bool *visited= new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}

	int from ,to ; cin>>from>>to;
	//map<int,int> m;
	path_bfs(edges,v,visited,from,to);


	return 0;
}