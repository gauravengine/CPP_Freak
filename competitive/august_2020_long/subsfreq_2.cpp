#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
const unsigned int M = 1000000007;

void fillmatrix(vector<vector<int> > matrix , int arr[], int n) 
{ 
  /* Number of subsequences is (2**n -1)*/
  unsigned int opsize = pow(2, n); 
  int mi=0,mj=0;
  /* Run from counter 000..1 to 111..1*/
  
  for ( int counter = 1; counter < opsize; counter++) 
  { vector<int> temp;
    for (int j = 0; j < n; j++) 
    {   
      /* Check if jth bit in the counter is set 
        If set then print jth element from arr[] */
      if (counter & (1<<j)) 
        cout << arr[j] << " ";
        temp.push_back(arr[j]);
      //cout<<"here";
    } 
    cout << endl;
    matrix.push_back(temp); 
    mi++;
  } 
} 
/*
void print_matrix (vector<vector<int> > matrix,int sizem ,int sizec){
  for(int i=0;i<sizem;i++){
    for(int j=0;j<sizec;j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}
*/

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  

  ll *dp= new ll[500000];
  dp[0]= 1;
  for(int i=1;i<500000;i++){
      dp[i] = ( dp[i-1]*2 )% M;
  }


  while(t--){
   int n;
   cin>>n;
   int* arr= new int[n]();
   unordered_map<int,int> freq;
   bool flag= true;   


   for(int i=0;i < n;i++){
    cin>>arr[i];
    freq[arr[i]] ++;
    if(freq[arr[i]] > 1) flag = false;
   }
   
  if(flag){  // sub- 2 case
    for(int i=n-1;i>=0 ;i--){
      cout<<dp[i]<<" ";
    }

    cout<<endl;
  }


   else{
    // for - 20 points 
    vector<vector<int> > matrix(dp[n] );
    fillmatrix(matrix, arr , n );

    for(int i=0;i<dp[n];i++){
         for(int j=0;j<n ;j++){
        cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
    }

    
  }

}

return 0;
}