#include<bits\stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
	int t;
	cin>>t;

	ll dp[101][101][2];
	dp[0][0][0]=0;
	dp[0][0][1]=0;
	dp[1][0][0]=1;
	dp[1][0][1]=1;
	for(int col=0;col<101;col++){
		dp[0][col][0]=0;
		dp[0][col][1]=0;
	}
	for(int n=2;n<101;n++){
		dp[n][0][0]=  (dp[n-1][0][0] + dp[n-1][0][1] ) %mod;
		dp[n][0][1]= (dp[n-1][0][0]) %mod;
	}
	for(int n=1;n<101;n++){
		for(int k=1;k<101;k++){
			dp[n][k][0]=(dp[n-1][k][0] +dp[n-1][k][1] ) %mod;
			dp[n][k][1]= (dp[n-1][k][0] + dp[n-1][k-1][1] ) %mod;
		}
	}





	while(t--){
		int data_set_number;
		cin>>data_set_number;
		int n; int k;
		cin>>n>>k;
		cout<<data_set_number<<" "<<dp[n][k][0]+dp[n][k][1]<<endl;

	}

	return 0;
}