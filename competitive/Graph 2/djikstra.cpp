#include<bits/stdc++.h>
using namespace std;

int min_distance(int* distance , bool* visited , int v){
	// returns min distance from unvisiteds 
	int min=-1;  
	for(int i=0;i<v;i++){
		if(!visited[i] && ( min==-1 || distance[i] < distance[min] ) ){

			min = i;

		}

	}
return min;

}

void djikstra(int** edges , int v){
	bool * visited = new bool[v]();
	int* distance= new int[v];
	for(int i=0;i<v;i++) distance[i] = INT_MAX;
	int *parent= new int[v];
	for(int i=0;i<v;i++) parent[i]=i;
	distance[0]=0; // let src be 0
	for(int i=0;i<v-1;i++){
		int x= min_distance(distance , visited ,v);
		visited[x]= true;
		for(int j=0;j<v;j++){
			if(edges[x][j] > 0 && !visited[j]){

				// update distance if greater
				if(distance[j] > distance[x] + edges[x][j]){
					parent[j]= x;
					distance[j] = distance[x] + edges[x][j];
				}

			} 


		}



	}
	
	for(int i=0;i<v;i++){
		cout<<i<<" "<<distance[i]<<"\n";
	}
	cout<<"printing parent array :"<<endl;
	for(int i=0;i<v;i++){
		cout<<"parent of "<<i<<" : "<<parent[i]<<endl;
	}


}

int main(){
	int v,e;
	cin>>v>>e;
	

	int** edges = new int* [v];
	for(int i=0 ;i<v ;i++){
		edges[i]= new int[v];
		for (int j = 0; j < v; j++)
		{
			edges[i][j]=0;
			
		}
	}	

	// taking edges and weight now
	for(int i=0;i<e;i++){
		int src,des,weight;
		cin>>src>>des>>weight;
		edges[src][des]= weight;
		edges[des][src]= weight;
	}

	// lets use functions 
	djikstra(edges , v);


	return 0;
}