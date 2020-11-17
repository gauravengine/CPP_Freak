#include<bits/stdc++.h>
using namespace std;
int getMaxMoney(int arr[], int n){
	int *dp=new int[n];
	dp[0]=arr[0];
	dp[1]= max(arr[1],arr[0]);
	for(int i=2;i<n;i++){
		dp[i]= max( (arr[i]+dp[i-2]) , (dp[i-1]) );
	}
    int ans=dp[n-1];
    delete [] dp;
    return ans;

}


// recursive approach
int getMaxMoney(int arr[],int i,int n){
	if(i>n){
		return 0;
	}
	int ans=max( getMaxMoney(i+1), arr[i]+getMaxMoney(i+2) );
	return ans;



}