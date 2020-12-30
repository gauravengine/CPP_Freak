#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        // int **arr= new int*[n];
        // for(int i=0;i<n;i++){
        //     arr[i]= new int[n];          
        // } 
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cin>>arr[i][j];
        //     }
        // }
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<n*n;i++){
            int x;
            cin>>x;
            pq.push(x);
        }
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
        
    }

    return 0;
}