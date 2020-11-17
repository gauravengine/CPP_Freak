#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<int> A){
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		m[A[i]] ++;
	}
	int freq[1001];
    for(int i=0;i<=1000;i++){
    	freq[i] = m[i];
    }
    int *dp= new int[1001];
    dp[0]=0;
    dp[1]=freq[1];

    for(int i=2;i<1001;i++){
    	dp[i]= max(dp[i-2] + freq[i]* i , dp[i-1]);
    }
	return dp[1000];

}