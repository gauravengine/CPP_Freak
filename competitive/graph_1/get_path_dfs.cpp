#include <iostream>
using namespace std;
#include<vector>

bool path_dfs(int** edges,int n,bool* visited,vector<int> &ans,int from,int to){
if(from==to ) {
	ans.push_back(from);
	return true;
	}

visited[from]=true;
for(int i=0;i<n;i++){
	if(i==from) continue;
	if(!visited[i] && edges[i][from]==1){
		visited[i]=true;
		if(path_dfs(edges,n,visited,ans,i,to)){
			
			ans.push_back(from);
			return true;
		}
		
		else continue;

	}
}

	return false;
}

int main(){
	int n,e;
	cin>>n>>e;
	int** edges= new int *[n];
	
	for(int i=0;i<n;i++){
		edges[i]= new int[n];
		for(int j=0;j<n;j++){
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

	int from ,to ; cin>>from>>to;
	
	bool *visited= new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	vector<int> ans;
	path_dfs(edges,n,visited,ans,from,to);
	
	//printing
	for(unsigned int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}


	return 0;
}