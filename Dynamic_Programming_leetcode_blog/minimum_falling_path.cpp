class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m= A.size();  // rows
        int n= A[0].size(); // columns
        if(m==1 && n==1) return A[0][0];
        int** dp= new int*[m];
        for(int i=0;i<m;i++){
            dp[i]= new int[n];
        }
        for(int j=0;j<n;j++){
            dp[0][j] = A[0][j];
        }
        int ans= INT_MAX;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int a=-10001,b=-10001,c=-10001;
            
                if(j-1>=0) a=dp[i-1][j-1];
                    //cout<<"a :"<<a<<endl;

                b=dp[i-1][j];
                   // cout<<"b :"<<b<<endl;
                
                if(j+1 < m) c= dp[i-1][j+1];
             //   cout<<"c :"<<c<<endl;
                if(a>-10001 && b>-10001 && c>-10001){
                    dp[i][j] = A[i][j] + min(a,min(b,c));
                }else if(a>-10001){
                    dp[i][j] = A[i][j] + min(a,b);
                }else{
                    dp[i][j] = A[i][j] + min(b,c);
                }
                if(i== m-1){
                  ans=min(ans,dp[i][j]);
                        
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
       // sort(dp[m-1],dp[m-1]+n);
        return ans;
    }
};