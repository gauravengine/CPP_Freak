#include<bits/stdc++.h>
using namespace std;

int find_min_weight(int* weight, int v, bool* visited){
	int minvertex=-1;
	for(int i=0;i<v;i++){
	
		if(!visited[i] && ( (minvertex== -1) || weight[i] < weight[minvertex] ) ) 
			minvertex = i;
	
	}
	return minvertex;

}

void prims(int** edges , int v){
	int* weight= new int[v];
	bool* visited= new bool[v]();
	int * parents = new int[v]; 
	// initialising weight
	for(int i=0;i<v;i++){
		weight[i]= INT_MAX;
	}
	parents[0]=-1;  // intial
	weight[0]=0;
	for(int i=0;i<v-1;i++){
		int min_weight_vertex= find_min_weight(weight,v,visited);
		// now checking for its neighbours and updating their weights if possible
		visited[min_weight_vertex]= true;
		for(int j=0;j<v;j++){
			if(edges[min_weight_vertex][j]!=0 && !visited[j]){
				if(weight[j] > edges[min_weight_vertex][j] ){
					weight[j]= edges[min_weight_vertex][j] ;
					parents[j]= min_weight_vertex;
				}

			}

		}



	}
  // now printing
	for(int i=1;i<v;i++){
		if(parents[i]<i){
			cout<<parents[i]<<" "<<i<<" "<<weight[i]<<endl;
		}
		else{
			cout<<i<<" "<<parents[i]<<" "<<weight[i]<<endl;
		}


	}




}

int main(){
	/*
	3 3
1 2 6
2 0 2
1 0 2
	*/
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

	//cout<<"here";
	
	// taking edges and weight now
	for(int i=0;i<e;i++){
		int src,des,weight;
		cin>>src>>des>>weight;
		edges[src][des]= weight;
		edges[des][src]= weight;
	}
	//cout<<"here";

	prims(edges,v) ;
	
	
	return 0;
}