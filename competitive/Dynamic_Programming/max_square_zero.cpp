
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    int** dp = new int*[row];
    for(int i=0;i<row;i++){
    	dp[i]= new int[col];
    }
    for(int j=0;j<col;j++){
    	if(arr[0][j]==1)
    		dp[0][j]=0;
    	else
    		dp[0][j]=1;
    }
// initialized first row
    for(int i=0;i<row;i++){
    	if(arr[i][0]==1)
    		dp[i][0]=0;
    	else
    		dp[i][0]=1;
    } // initialized first column


   for(int i=1;i<row;i++){
   	for(int j=1;j<col;j++){
   		if(arr[i][j]==1)
   			dp[i][j]=0;
   		else
   			dp[i][j]= min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
   	}
   }
int max=dp[0][0];
for(int i=0;i<row;i++){
	for(int j=0;j<col;j++){
		if(dp[i][j]>max){
			max= dp[i][j];
		}
	}
}
    
    delete [] dp;
    return max;
}