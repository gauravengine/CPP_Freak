#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > matrix;

vector<int> vector_creator(int** edges, int n, int starting_vertex, bool* visited)
{
	vector<int>temp;
	queue<int> q;
	q.push(starting_vertex);
	visited[starting_vertex] = true;
	while (!q.empty())
	{
		temp.push_back(q.front());
		int current_element = q.front();
		for (int i = 1; i < n; i++)
		{
			if (i == current_element)
			{
				continue;
			}
			
			if (edges[current_element][i] == 1 && visited[i]==false)
			{
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();
	}
	return temp;
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

	for (int i = 0; i < e; i++)
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
			matrix[i]=vector_creator(edges,v,i,visited);
			for(int j=0;j<matrix[i].size();j++){
				cout<<matrix[i][j]<<" ";
			}
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