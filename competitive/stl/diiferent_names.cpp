#include<bits/stdc++.h>
using namespace std;
int main()
{
   unordered_map<string,int> frequency;
   string names;  int count=0;
   getline(cin,names);
   stringstream ss(names);
   string word;
   while(ss>>word){
frequency[word]++;
   }



   for(auto it:frequency){
     if(it.second>1){ cout<<it.first<<" "<<it.second;
     cout<<endl; count++;}

   }

   if(count==0) cout<<-1;
	return 0;
}
