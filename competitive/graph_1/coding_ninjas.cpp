#include<string>

bool all(char Graph[][MAXN],int n, int m ,  int i,int j,string find,bool** visited){
	if(find==NULL) return true;   // base case all chars found
	// now i have to find find[0] in nbd of graph[i][j]
	char to_be_found = find[0];
	
} 


int solve(char Graph[][MAXN],int n, int m)
{
	bool ** visited = new bool*[n]	;
	for(int i=0;i<n;i++){
		visited[i]= new bool[m]; 
		for(int j=0;j<m;j++){
		 
			visited[i][j] = false;
		}
	}
	string find = "odingninja";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(Graph[i][j] == 'c'){
				if( all(Graph,i,j,find) )	// check for others if poora codingninja ban raha h ?
				{
					return 1;
				}
				else {
					// make visted false again and continue

					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							visited[i][j] = false;
						}
					}
					// done
				}
			}

		}
	}


	return 0;
}