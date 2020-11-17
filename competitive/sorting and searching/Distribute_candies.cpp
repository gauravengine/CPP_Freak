#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n; ll k; cin>>k;
		ll arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		cout<<arr[n-k]<<endl;

	}
	return 0;
} */
bool check (ll arr[],int size,ll studs, int mid){
	ll stud_count=0;
	for(int i=0;i<size;i++){
		stud_count+=(arr[i]/mid);
		if(stud_count>=studs) return true;
	}
	return false;
}


int main(){
int t; cin>>t;
while(t--){  
	int n; cin>>n; ll k; cin>>k;
	ll arr[n]; cin>>arr[0]; ll max= arr[0];
	for(int i=1;i<n;i++){
		cin>>arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
  
 ll ans=0;
  ll min=0; // max already defined
while(min<=max){
	int mid=(min+max)/2;
	if(check(arr,n,k,mid)){
		min=mid+1;
		ans=mid;
	}
    else{
    	max=mid-1;
    }

    
}
cout<<ans<<endl;

}

return 0;
}

