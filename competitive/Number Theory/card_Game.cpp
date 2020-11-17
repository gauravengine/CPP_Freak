// Created by Yadav_Gaurav
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
#define mod 1000000007


using namespace std;
using ll = long long;

bool func(ll x , vector<pair<ll,ll>> &k_factors_temp, vector<pair<ll,ll>> &k_factors){
	// this function will store the values of powers of prime of k_factors in k_temp and then 
	// check if all the powers have become equal or greater than those in k
	// if greater it will return true
	// else it will modify the k_temp for next x
	for(  ll i=0;i<k_factors.size();i++){
		if(x%k_factors[i].first ==0){
			ll temp=0;
			while(x%k_factors[i].first==0){
				x/= k_factors[i].first;
				temp++;
			}
			k_factors_temp[i].second += temp;
		}
	}

	for(  ll i=0;i<k_factors.size();i++){
		if(k_factors[i].second > k_factors_temp[i].second){
			return false;
			break;
		}

	}

	return true;
}


void remove(vector<pair<ll,ll>> &k_factors_temp , vector<pair<ll,ll>> &k_factors,ll x ){
// this function will remove powers of k_factors from k_factors_temp in x
	for(  ll i=0;i<k_factors.size();i++){
		if(x%k_factors[i].first==0){
			ll temp=0;
			while(x%k_factors[i].first==0){
				x/= k_factors[i].first;
				temp++;
			}
			k_factors_temp[i].second -= temp;
		}
	}


}

bool ok(vector<pair<ll,ll>> &k_factors_temp , vector<pair<ll,ll>> &k_factors	){
	for(  ll i=0;i<k_factors.size();i++){
		if(k_factors[i].second > k_factors_temp[i].second){
			return false;
			break;
		}

	}

	return true;


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; ll k;
    cin>>n>>k;
    ll * arr= new ll[n];
    for(ll i=0; i<n; i++) {
    	cin>>arr[i];
    } 
    ll temp=k;
    // making k's factors
    vector<pair<ll,ll>> k_factors;
    for(ll i=2;i*i<=k;i++){
    	if(k%i==0){
    		//ll temp=k;
    		ll power_i=0;
    		while(temp%i==0){
    			temp/=i;
    			power_i++;
    		}
    		k_factors.push_back(make_pair(i,power_i));
    	}
    }
    if(temp != 1){
    	k_factors.push_back(make_pair(temp,1));
    }
    // done with k factors
    vector<pair<ll,ll>>  k_factors_temp= k_factors;
    for( ll i=0;i<k_factors_temp.size();i++){
    	k_factors_temp[i].second =0;
	}

    ll ans=0; ll temp_j=-1;
    for(ll i=0;i<n;i++){
    	// remove the powers of arr[i-1] from k_factors_temp;

    	if(i>0) remove(k_factors_temp,k_factors,arr[i-1]);
    	
    	// checking if k_factors_temp is ok after incrementing i (maybe i-1 ) wasnt contributing 

    	if(ok(k_factors_temp,k_factors)){
    		ans += n-temp_j; 
    	}
    	else{
    	
    	//if(i==temp_j && i!=0 ) remove(k_factors_temp,k_factors,arr[i]);
    	for(ll j=temp_j+1;j<n;j++){
    		if(func(arr[j], k_factors_temp,k_factors) ){
    			ans+= n-j;
    			//db3(i,j,ans);
    			temp_j = j;
    			//db1(temp_j);
    			break;
    		}

    	}  
    	}	
	}



    cout<<ans;
    return 0;
}