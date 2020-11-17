#include<queue>
void BFS(int** edges, int n,bool* visited,int sv){
visited[sv]= true;
queue<int> q;
q.push(sv);
while(!q.empty()){
	int front= q.front();
	for(int i=0;i<n;i++){
		if(i==sv ) continue;
		if(visited[i]== false && edges[front][i]== 1){
			q.push(i);
			visited[i]= true;
		}

	}

	q.pop();

}

}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** edges= new int*[n];
	for(int i=0;i<n;i++){
		edges[i]= new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		
		int a,b;
		a=u[i]-1;
		b=v[i]-1;
		edges[a][b]=1;
		edges[b][a]=1;

	}
	int count=0;
	bool* visited= new bool[n];
	for(int i=0;i<n;i++){	
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			BFS(edges,n,visited,i); /	
			count++;
		}
	}


	return count;
}