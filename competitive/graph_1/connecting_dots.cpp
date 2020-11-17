bool check(char board[][MAXN], int n,int m,int i,int j, char target,bool** visited){
	
	// base case
	visited[i][j]= true;
	int sum=0;
	//up 
	if(i-1 >=0 && board[i-1][j]==target && visited[i-1][j] == true) sum++;
	//down
	if(i+1 < n-1 && board[i+1][j] == target && visited[i+1][j] == true  ) sum++;

	//left
	if(j-1>=0 && board[i][j-1] == target && visited[i][j-1] == true ) sum++;

	//right
	if(j+1<m-1 && board[i][j+1] == target && visited[i][j+1] == true ) sum++;

	if( sum >= 2 ) return true;

	// recursive funcs 

	// up
	if(i-1 >0 && board[i-1][j]==target && visited[i-1][j] == false){

		if(check(board,n,m,i-1,j,target,visited)){
			return true;
		}
		else{
			visited[i-1][j]= false;
		} 
	}

	//down
	if(i+1 >=0 && board[i+1][j]==target && visited[i+1][j] == false){

		if(check(board,n,m,i+1,j,target,visited)){
			return true;
		}
		else{
			visited[i+1][j]= false;
		}
	} 
	// left
	if(j-1>=0 && board[i][j-1] == target && visited[i][j-1] == false ) {

		if(check(board,n,m,i,j-1,target,visited)){
			return true;
		}
		else{
			visited[i][j-1]= false;
		}
	}
	//right
	if(j+1<m-1 && board[i][j+1] == target && visited[i][j+1] == false ) {

		if(check(board,n,m,i,j+1,target,visited)){
			return true;
		}
		else{
			visited[i][j+1]= false;
		}
	}




	return false;
}

int solve(char board[][MAXN],int n, int m)
{
	bool** visited = new bool*[n];
	for(int i=0;i<n;i++){
		visited[i]= new bool[m];
		for(int j=0;j<m;j++) 
		{
			visited[i][j]=false;
		}
	}


	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++){

			if(check(board,n,m,i,j,board[i][j],visited)){
				return 1;
			}
			else {
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++) 
					{
						visited[i][j]=false;
					}
				}
				// visited  ko false karo
				// continue

			}
		}
	}




	return 0;
}