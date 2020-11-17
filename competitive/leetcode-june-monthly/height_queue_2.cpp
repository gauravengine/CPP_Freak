#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<vector<int> > v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << "[";
      for(int j = 0; j <v[i].size(); j++){
         cout << v[i][j] << ", ";
      }
      cout << "],";
   }
   cout << "]"<<endl;
}
bool comparator(const vector<int> &a,const vector<int> &b){
    if(a[0]!=b[0])
        return a[0]<b[0];
    else
        return a[1]>b[1];
}
class Solution {
public:
   vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      sort(people.begin(), people.end(), comparator);
      int k=people.size();
       vector<vector<int>> ans;
            ans.resize(k);
            for(int i=0;i<k;i++){

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
                ans[j-1][0]=a;
                ans[j-1][1]=c;
                
            }



      return ans;
   }
};
int main(){
   Solution ob;
   vector<vector<int>> v = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
   print_vector(ob.reconstructQueue(v));
   return 0;
}