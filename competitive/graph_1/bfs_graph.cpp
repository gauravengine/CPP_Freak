#include<iostream>
#include<queue>
using namespace std;


void BFS(int** edges,int v,bool* visited,int sv){

	queue<int> q;
	q.push(sv);
	visited[sv]=true;	
	while(!q.empty()){
		int sv=q.front();
		cout<<q.front()<<" ";
		
		for(int i=0;i<v;i++){
			if(i==sv) continue;
			if(edges[i][sv]==1){
				if(visited[i]==false){
					visited[i]=true;
					q.push(i);
				}
			}
		}
		q.pop();

	}

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
	for(int i=0;i<v;i++){
		if(!visited[i]){
			BFS(edges,v,visited,i);
			cout<<endl;
		}
	}

	delete [] visited;
	for(int i=0;i<v;i++){
		delete [] edges[i];
	}

	delete []  edges;
	return 0;
}