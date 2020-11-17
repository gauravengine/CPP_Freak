// Created by Yadav_Gaurav
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define mod 1000000007
#define endl "\n"
using namespace std;
using ll = long long;
#define MAX 1000001
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int* factors= new int [MAX];
    for(int i=0;i<MAX;i++){
      factors[i]=0;
    }

    for(int i=2;i<MAX;i++){
      if(factors[i]== 0){
        // make all its factors +1;
        
        for(int j=i;j<MAX;j+=i){
          factors[j]++;
        }
      }
    }

    vector<vector <int> > ans(11, vector<int>(MAX,0) );
    // cant iterate on factor maybe more than 10
    for(int i=1; i<11; i++) {
      for(int j=1;j<MAX;j++){
        if(factors[j] == i){
          ans[i][j]= ans[i][j-1] +1;  // o boy 
        }
        else{
          ans[i][j]= ans[i][j-1];
        }
      }
    }


    int t;
    cin>>t;
    
    while(t--){
       	int a,b,n;
        cin>>a>>b>>n;
        if(n==0){
          if(a<=1)  cout<<1;
          else cout<<0;

          
         }

        else{
          if(a>=1)
          cout<<ans[n][b]- ans[n][a-1];
          else
          cout<<ans[n][b];


        }
     //   db1(ans[2][10]);
       // db1(factors[10]);



        cout<<'\n';
    }
    return 0;
}