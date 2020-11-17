#include<bits/stdc++.h>
bool comparator(const vector<int> &a,const vector<int> &b){
    if(a[0]!=b[0])
        return a[0]<b[0];
    else
        return a[1]>b[1];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            sort(people.begin(),people.end(),comparator);
            int k=people.size();
        for(int i=0;i<k;i++){
                
                for(int j=0;j<2;j++){
                  cout<<people[i][j]<<" ";
                } cout<<"\n";
        }
           // vector<vector<int>>* ans= new vector<vector<int>>[k];
            vector<vector<int>> ans;
            ans.resize(k);
            for(int i=0;i<k;i++){
                /*ans[i]= new vector<int>[2];
                for(int j=0;j<2;j++){
                    ans[i][j]=-1;
                } */
                ans[i].resize(2);
                for(int j=0;j<2;j++){
                    ans[i][j]=-1;
                } 
                
            }
        
            for(int i=0;i<k;i++){
                int a=people[i][0];
                int c=people[i][1];
                int b=people[i][1]+1;
                int pos;
                int j=0;
                while((b)!=0){
                if(ans[j][0]==-1){
                    j++; 
                    b--;
                }     
                else j++;
                }
                ans[j][0]=a;
                ans[j][1]=c;
                
            }
        
    
        return ans;
    }
};