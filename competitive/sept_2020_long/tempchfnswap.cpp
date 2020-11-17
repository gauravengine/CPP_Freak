#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define mod 1000000009

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	vector<ll> sum;
	sum.push_back(0);
	for(int i=1;i<100000;i++){
		ll s= (sum[i-1] + i);
		sum.push_back(s);

	} 
	unordered_map<int,int> freq;
	while(t--){
		//int n; cin>>n; 
		
		// hard coding for 23 
		for(int n=1;n<=2000;n++){
			int ans=0;

			// checking for pecial case 
			/*
			int pecial =  (-1 + sqrt(1+4*sum[n]) )/2;

			if( 2*sum[pecial] == sum[n] ){
				//cout<<"hi"<<endl;
				ans += ( (pecial)*(pecial-1) ) / 2;
				pecial = n-pecial;
				ans += ( (pecial)*(pecial-1) ) / 2;


			} */

			if(sum[n]%2 ==0){
			int just_low= sum[n]/2 - (n-1);
			int first_index= lower_bound(sum.begin(),sum.end(),just_low) - sum.begin();	
			int sum_till_first_index= sum[first_index];
			int sum_till_last=sum[n] - sum[first_index];
			
			//cout<<"first_index : "<<first_index<<endl;
			//cout<<"sum_till_first_index : "<<sum_till_first_index<<endl;
			//cout<<"sum_till_last : "<<sum_till_last<<endl;


			while(sum_till_first_index < sum_till_last){
				int difference= sum_till_last- sum_till_first_index;
				int target_diff= difference/2;
				for(int i= first_index+1;i<=n;i++){
					if(i - target_diff >0 && i-target_diff <= first_index) ans++;
				}
				first_index= first_index+1;
				sum_till_first_index=sum[first_index];
				sum_till_last=sum[n]- sum_till_first_index;

				//cout<<"first_index : "<<first_index<<endl;
				//cout<<"sum_till_first_index : "<<sum_till_first_index<<endl;
				//cout<<"sum_till_last : "<<sum_till_last<<endl;
			// first_index+1  se n tak if first_index+1-target_diff >0 and <= first_index then ans++; and print ans
			// update first_index sum_till_first and sum_till_last
			// continue till sum_till_first > sum_till_last
			}

			}
			
			else ans=0;
			cout<<n<<" has ans : "<<ans<<endl;
			freq[ans] ++;
			}



			cout<<"elements having frequency 1 are : "<<endl;
			for(int i=1;i<1000;i++){
				if(freq[i]==1) cout<<i<<" ";
			}

	}

	return 0;
}