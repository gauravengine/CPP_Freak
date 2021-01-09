#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends

typedef long long ll;

int lcshelper(int x, int y, string s1, string s2,ll **memo){
    if(x<=0 || y<=0) return 0;
   
    
    if(memo[x][y]> -1) return memo[x][y];
    
    if(s1[0]==s2[0]){
        return memo[x][y] =1+ lcshelper(x-1,y-1,s1.substr(1),s2.substr(1),memo);
        

    }
    int opt1= lcshelper(x,y-1,s1,s2.substr(1),memo);
    int opt2= lcshelper(x-1,y,s1.substr(1),s2,memo);
    return memo[x][y]=max(opt1,opt2);
    // if(x<=0 || y<=0) return 0;
    // if(memo[x][y]> -1) return memo[x][y];
    // int ans;
    // if(s1[0]==s2[0]){
    //     ans= 1+ lcshelper(x-1,y-1,s1.substr(1),s2.substr(1),memo);
    // }
    // else{
    //      int opt1= lcshelper(x,y-1,s1,s2.substr(1),memo);
    //     int opt2= lcshelper(x-1,y,s1.substr(1),s2,memo);
    //     ans= max(opt1,opt2);
    // }
    // return memo[x][y]=ans;
}

int lcs(int x, int y, string s1, string s2){
    ll **memo= new ll*[x+1];
    for(int i=0;i<=x;i++) {
        memo[i]= new ll[y+1];
        for(int j=0;j<=y;j++){
            memo[i][j]=-1;
        }
    }
    // for(int i=0;i<=x;i++) {
        
    //     for(int j=0;j<=y;j++){
    //        cout<<memo[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //memset(memo,-1,sizeof(memo));
    // for(int i=0;i<x;i++) {
        
    //     for(int j=0;j<y;j++){
    //       cout<<memo[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return lcshelper(x,y,s1,s2,memo);
    
}

