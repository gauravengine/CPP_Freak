
int solve(int n,int m,vector<int>u,vector<int>v)
{	
	int** edges= new int *[n];
	
	for(int i=0;i<n;i++){
		edges[i]= new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		
		int f= u[i]-1;
		int s=v[i]-1;
		edges[f][s]=1;
		edges[s][f]=1;

	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!= j){
			if(edges[i][j] == 1){
				for(int k=0;k<n;k++){
					if(k != i){
						if(edges[j][k]==1){
							if(edges[i][k] == 1){
								count++;
							}
						}
					}
				}
			}
		}
		}
	}		


return count/6 ;
}