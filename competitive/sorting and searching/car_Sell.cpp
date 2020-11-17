#include<bits/stdc++.h>
using namespace std;
#define MOD (1000000000 + 7)
int main(){
int t; cin>>t;
while(t--){
int n; cin>>n;
vector<long long > v;
for(int i=0;i<n;i++)
	{ long long data; cin>>data;
    	v.push_back(data);  	
	}
sort(v.begin(),v.end());


long long profit =0; long long i=0;;
auto it= v.rbegin();
while( it!=v.rend())
{
	profit += max((long long)0,(*it -i));
	i++; it++;
}
profit =(profit%MOD);
cout<<profit<<endl;
}

}