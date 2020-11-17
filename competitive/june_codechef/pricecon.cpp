#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		ll raw_sum=0,ceil_sum=0;
	for(int i=0;i<n;i++){
		raw_sum+=arr[i];
		if(arr[i]>k)
			ceil_sum += k;
		else
			ceil_sum += arr[i];

	}		
	cout<<(raw_sum - ceil_sum)<<endl;




	} 

return 0;
}
