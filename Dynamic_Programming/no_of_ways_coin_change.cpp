#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount,unordered_map<string,int> &dp,int last) {
        // if(amount ==0) return 1;
        // sort(coins.begin(),coins.end());
        
        // dp[0]=1;
        // for(int i=1;i<=amount;i++){
        //     for(int j=0;j<coins.size();j++){
        //         if(coins[j]>i) break;
        //         //dp[i]= min(dp[i],dp[i-coins[j]]);
		// 		dp[i] +=dp[i-coins[j]];
        //     }
        // }
        
        // return dp[amount];
        if(amount <0) return 0;
        if(last <0) return 0;
        if(amount ==0) return 1;
        string s=to_string(amount) +"@"+to_string(last);
        //cout<<"s :"<<s<<'\n';
        if(dp.find(s)!=dp.end()) return dp.at(s);
        return dp[s]=coinChange(coins,amount - coins[last],dp,last)+ coinChange(coins,amount,dp,last-1);
}


int main() 
{
	int amount ; cin>>amount;
	int n; cin>>n;
	vector<int> coins(n);
	for(int i=0;i<n;i++) cin>>coins[i];
	unordered_map<string,int> dp;
	cout<<coinChange(coins,amount,dp,n-1)<<endl;
    // for(int i=0;i<=amount;i++) cout<<dp[i]<<" ";
    // cout<<endl;
	return 0;
}