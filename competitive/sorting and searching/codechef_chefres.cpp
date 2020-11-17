#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int answer(vector<pair<int,int>> vect,int time)
{ 
  int position=lower_bound(vect.begin(),vect.end(),make_pair(time,0))-vect.begin();
if(position==0){
  return vect[position].first - time;
}  
  else
{
  if(position==vect.size()){
    if(vect[position-1].second>time) return 0;
    else return -1;
  }
  else{
    if( vect[position-1].second > time ) return 0;
    else{
    return vect[position].first - time ;  }

  }
} 

/*else{
  int ans=-1;
if(vect[position-1].second>time) ans=0;
else if(position<vect.size())
{
  ans=vect[position].first-time;
}
   
   return ans;
}
*/



 
} 
int main(){
  int t;
  cin>>t;
  while(t--){
      int n,m; cin>>n>>m;
      
      vector<pair<int,int>> vect;
      for(int i=0;i<n;i++)
      {int start,end;
        cin>>start>>end;
        vect.push_back(make_pair(start,end));
      }

      sort(vect.begin(),vect.end()); //sorted the vector of pairs
      

   while(m--)
      { int time; cin>>time;
        int position=lower_bound(vect.begin(),vect.end(),make_pair(time,0))-vect.begin();
        int ans=answer(vect,time);
cout<<ans<<endl;
  

      }
    }
    return 0;
}
