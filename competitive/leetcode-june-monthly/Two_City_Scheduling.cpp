#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
bool sorting(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second<b.second);
}



int twoCitySchedCost(vector<vector<int>> &costs)
    {
        vector<pair<int,int>> a,b;
        for(unsigned int i=0;i<costs.size();++i){
            a.push_back(make_pair(i,costs[i][0]));
            b.push_back(make_pair(i,costs[i][1]));
        
        }
        vector<int> output;
        sort(a.begin(), a.end(), sorting);
        sort(b.begin(), b.end(), sorting);
        int n=costs.size()/2;
        
        unordered_map<int,int> visited_a,visited_b; // 0 if not visited else 1
        // simple sum karta hun fer dekhunga baki cases
        cout<<endl;
        bool flag =true;
        int w=a[n-1].first;
        int m=n;
        do{
        int sum=0;

        for(int i=0;i<n;i++){
             sum += a[i].second;
             cout<<a[i].second<<" ";
            visited_a[i]=1;// means i came here before

        }
        visited_a[a[n-1].first]=0;
        visited_a[w]=1; // made it 1 meaing i came here 
        cout<<endl;
        for(int i=0;i<2*n;i++){
            if(visited_a[i]==0) {
                sum += b[i].second;
                cout<<b[i].second<<" ";
            }
        }
        cout<<endl;
        output.push_back(sum);
        if(a[m-1].second==a[m].second){
            //w=a[m].first;
            m++;
            w=a[m-1].first;


        }
        else flag=false;
        }while(flag== true);


        // now same cases for b

        bool flag_b =true;
        int w_b=b[n-1].first;
        int m_b=n;
        do{
        int sum=0;

        for(int i=0;i<n;i++){
             sum += b[i].second;
             cout<<b[i].second<<" ";
            visited_b[i]=1;// means i came here before

        }
        visited_b[b[n-1].first]=0;
        visited_b[w_b]=1; // made it 1 meaing i came here 
        cout<<endl;
        for(int i=0;i<2*n;i++){
            if(visited_b[i]==0) {
                cout<<i<<" ";
                sum += a[i].second;
                cout<<a[i].second<<" "; cout<<" came here ";
            }
        }
        cout<<endl;
        output.push_back(sum);
        if(b[m_b-1].second==b[m_b].second){
            //w_b=b[m_b].first;
            m_b++;
            w_b=b[m_b-1].first;


        }
        else flag_b=false;
        }while(flag_b== true);
        





        sort(output.begin(),output.end());
        return output[0];

    
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