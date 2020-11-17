#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll dp[101][101][2];
int col;
ll adj(int n,int k,int starting_bit/*,ll dp[101][101][2]*/){
	if(n<=0){
		return 0;
	}
	if(k<0){
		return 0;
	}
	if(n<=k){
		//dp[n][k][starting_bit]=0;
		return 0;
	}
	ll ans;
	/*if(dp[n][k][starting_bit]>-1){
		return dp[n][k][starting_bit];
	} */
	/*
	if(n==2){
		if(k==1){
			if(starting_bit=1) return 1;
			else return 2;
		}
		if(k==0){
			if(starting_bit==1) return 1;
			if(starting_bit==0) return 2;
		}
	} 
	
	if(n==1 && k==1){
		if(starting_bit==0) return 0;
		if(starting_bit==1) return 1;
	} */
	if(n==1){
		if(k==0) {
			
			return 1;
		}
		else {
			
			return 0;}
	}
	
	if(starting_bit==0){
			 ans = adj(n-1,k,0)+adj(n-1,k,1);
	}

	if(starting_bit==1){
		 ans= adj(n-1,k,0) +adj(n-1,k-1,1);
	}
	

	return ans;
} 
int main(){
	int t;
	cin>>t;

	

	while(t--){
		int data_set_number;
		cin>>data_set_number;
		int n; int k;
		cin>>n>>k;
		cout<<data_set_number<<" "<<adj(n,k,0)+adj(n,k,1)<<endl;

	}

	return 0;
}