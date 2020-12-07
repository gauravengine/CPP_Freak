class Solution {
public:
    unordered_set<int> travel; // to store travelling days;
    unordered_map<int,int> validity;
    
    int dp[366][4][366];
    int solve(int dno,int pass, int last_buy,vector<int>& costs ){ 
        if(dno == 366){
            return 0;  // no more dollars /|
        
        }        
        if(dp[dno][pass][last_buy] != -1){
            return dp[dno][pass][last_buy];
        } 
        if(travel.find(dno) == travel.end()){
            return dp[dno][pass][last_buy]=solve(dno+1,pass,last_buy,costs) ; // i m not traveeling on this day
        }else{
            if(dno < last_buy+validity[pass] ){
                return dp[dno][pass][last_buy] = solve(dno+1,pass,last_buy,costs); // already bought the pass
            }
            else{
                // now i need to make a decision for pass buying
                // one day pass
                int opt1=  costs[0] + solve(dno+1,1,dno,costs);
                int opt2=  costs[1] + solve(dno+1,2,dno,costs); // for 7 days
                int opt3=  costs[2] + solve(dno+1,3,dno,costs); // for 30 days
                return dp[dno][pass][last_buy] = min({opt1,opt2,opt3}) ;
            }
        }
        
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        validity[0]= 0;
        validity[1]= 1;
        validity[2]= 7;
        validity[3] = 30;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<days.size();i++){
            travel.insert(days[i]);
        }
        
    return solve(1,0,0,costs);
    }
     
};