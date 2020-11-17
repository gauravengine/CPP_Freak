#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<int> v; int size=0;
		for(int i=0;i<n;i++){
			ll x;
			cin>>x;
			if(x==1) {
				v.push_back(i+1);
				size++;
			}
		}
		ll ans=0;
		if(size==1) ans=-1;
		else if(size==0) ans=0;

	


	else{
		
		for(int i=1;i<size;i++){
			ans +=min( v[i]-v[i-1],v[i]-);
		}
	}
		cout<<ans<<endl;

	}


	return 0;
}