#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool possible(ll n ,ll mid){
	ll k=mid;
	ll curr =n;
	ll sum=0;
	while(curr>0){
		sum = sum + min(curr,k); 
		curr=curr-k;
		curr= curr - (curr/10);
	}
	if(2*sum>= n) return true;
	else return false;

}
int main(){

	ll n;
	cin>>n;
	
	ll start=1;
	ll  end=n;
	ll ans=1;
	while(start<=end){
		ll mid= start+(end-start)/2;
		if(possible(n,mid)){
			 ans=mid;
			end=mid-1;

		}
		else{
			start=mid+1;
		}
	}

cout<<ans<<endl;
	return 0;
}