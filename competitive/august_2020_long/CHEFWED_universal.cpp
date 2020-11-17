#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
const unsigned int M = 1000000007;

int main() {
	
	int t;
	cin>>t;

	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int *arr=new int[n+1];

	    for(int i=1;i<n+1;i++)
	    {
	        cin>>arr[i];
	    }

	    int *dp=new int[n+1];
	    dp[0]=0;
	   
	    
       
        
	    for(int i=1;i< n+1 ;i++)
	    {
	      map<int ,int> freq;
	      int ans=INT_MAX;
	      int args=0;

          for(int j=i;j>0;j--)
          {
              freq[arr[j]]++;
              if(freq[arr[j]]==2)
               args += 2;
               
              if(freq[arr[j]]>2)
                args ++;
                
            ans= min(ans,args + k + dp[j-1]);
          }
          
          dp[i]=ans;
	      

	    }
	     cout<<dp[n]<<endl;
	    
	}
	
	return 0;
}