#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
bool sorting(const vector<int> &a,const vector<int> &b){
    return (abs(a[1]-a[0]) > abs(b[1]-b[0]));
}
int twoCitySchedCost(vector<vector<int>>& costs) {
        /*
        for(unsigned int i=0;i<costs.size();i++){
            costs[i][2]=abs(costs[i][1]-costs[i][0]);
        } */
        sort(costs.begin(),costs.end(),sorting);
        for(unsigned int i=0;i<costs.size();i++){
            for(int j=0;j<2;j++){
               // cout<<j<<" "<<endl;
                cout<<costs[i][j]<<" ";
            }
            cout<<endl;
        }
        

        int N = costs.size() / 2;
               int c1 = 0;// counter for the city A
                int c2 = 0;// counter for the city B
                int ans = 0;
               int  i = 0;
        while (i < 2 * N) {
            if ((costs[i][0] <= costs[i][1] && c1 < N) || c2 == N) {
                ans += costs[i++][0];
                c1++;
            } else {
                ans += costs[i++][1];
                c2++;
            }
        }
        return ans;
        
        
        
        
        
    }

int main(){
    int size;
    cin>>size;
    vector<vector<int>> a;
    for(int i=0;i<size;i++){
        vector<int> temp;
        int x,y;
        cin>>x>>y;
        temp.push_back(x);
        temp.push_back(y);
        a.push_back(temp);
    }
    cout<<twoCitySchedCost(a);

    return 0;
}