// passed 40 point rest me TLE h 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define mod 1000000007

/*
ll binary_pecial(ll pecial){



}
*/

ll binary(ll just_low ,ll n){
	ll low=1;
	ll mid;
	ll high= n;
	while(low<high){
		mid = (low + (high - low) / 2) ; 

		ll sum_mid = ( (mid)*(mid+1)/2  ) ;
		if (just_low <= sum_mid) { 
            high = mid; 
        } 
  
        // If X is greater arr[mid] 
        // then find in right subarray 
        else { 
            low = mid + 1; 
        } 
	}
    //cout<<"low : "<<low<<endl;
	return low; 


}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	
	/*
	vector<ll> sum;
	sum.push_back(0);
	
	for(ll i=1;i<10000000;i++){
		ll s= sum[i-1] + i;
		sum.push_back(s);
		
	} 
	*/


	while(t--){
		ll n; cin>>n; 
		
		ll sum= (n)*(n+1)/2;
		
			ll ans=0;

			// checking for pecial case 
			ll pecial =  (-1 + sqrt(1+4*sum) )/2;
			ll sum_pecial=(pecial)*(pecial+1)/2;
			if( 2*sum_pecial == sum ){
				//cout<<"hi"<<endl;
				ans += ( (pecial)*(pecial-1) ) / 2;
				pecial = n-pecial;
				ans += ( (pecial)*(pecial-1) ) / 2;


			}

			if(sum%2 ==0){
			ll just_low= sum/2 - (n-1);
			
			ll first_index=binary(just_low,n) ;
			
			
			ll sum_till_first_index=( (first_index)*(first_index+1)/2 ) ;
			ll sum_till_last=(sum - sum_till_first_index) ;

			//cout<<"first_index : "<<first_index<<endl;
			//cout<<"sum_till_first_index : "<<sum_till_first_index<<endl;
			//cout<<"sum_till_last : "<<sum_till_last<<endl;


			while(sum_till_first_index < sum_till_last){
				ll difference= sum_till_last- sum_till_first_index;
				ll target_diff= difference/2;
				
				/*
				for	(ll i= first_index+1;i<=n;i++){
						if(i - target_diff >0 && i-target_diff <= first_index) ans++; 
				}
				*/
				ll i= first_index+1;
				if(i-target_diff <=0){
					if(n-target_diff >0) ans+= n-target_diff;

				}
				if(i-target_diff > 0){

					ans+= min( n-first_index ,target_diff );

				}

				first_index= first_index+1;
				sum_till_first_index=(sum_till_first_index + first_index);
				sum_till_last= (sum_till_last - first_index);
				

				//cout<<"first_index : "<<first_index<<endl;
				//cout<<"sum_till_first_index : "<<sum_till_first_index<<endl;
				//cout<<"sum_till_last : "<<sum_till_last<<endl;
			// first_index+1  se n tak if first_index+1-target_diff >0 and <= first_index then ans++; and print ans
			// update first_index sum_till_first and sum_till_last
			// continue till sum_till_first > sum_till_last
			}

			}
			
			else ans=0;
			
			cout<<ans<<endl;
			

	}

	return 0;
}