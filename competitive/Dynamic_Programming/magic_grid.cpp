#include<iostream>
#include<climits>
using namespace std;

int min_health(int** healthgrid,int si,int sj,int ei,int ej,int** dp){
if((si==ei&& sj==ej-1 ) || (si==ei-1 && sj==ej ) ){
	if(healthgrid[si][sj]<=0){
		return (1-healthgrid[si][sj]);
	}
	else
		return 1;
}
	if(si>ei ||sj>ej){
		return INT_MAX;
	}
	if(dp[si][sj]>-1){
		return dp[si][sj];
	}


	int option_1= min_health(healthgrid,si,sj+1,ei,ej,dp);// right one
	int option_2= min_health(healthgrid,si+1,sj,ei,ej,dp);// downward one
	int good= min(option_2,option_1);
	/*
	if(healthgrid[si][sj]<0){
		return good- healthgrid[si][sj];
	}
	else
		return 1; */
	int ans=good - healthgrid[si][sj];
	if(ans<1){
		//return 1;
		dp[si][sj]=1;
		return dp[si][sj];
	}
	dp[si][sj]= ans;
	return dp[si][sj];

}

int main(){
 int t;
 cin>>t;
 while(t--){
 	int row,col;
 	cin>>row>>col;
 	int** healthgrid= new int*[row];
 	for(int i=0;i<row;i++){
 		healthgrid[i]= new int[col];
 		for(int j=0;j<col;j++){
 			cin>>healthgrid[i][j];
 		}
 	} 
 	// initializing dp matrix
 	int** dp=new int*[row];
 	for(int i=0;i<row;i++){
 		dp[i]= new int[col];
 		for(int j=0;j<col;j++){
 			dp[i][j]=-1;
 		}
 	}

 	cout<<min_health(healthgrid,0,0,row-1,col-1,dp)<<endl;;
 }


return 0;
}