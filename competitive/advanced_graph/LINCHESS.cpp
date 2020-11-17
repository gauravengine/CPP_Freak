#include<bits/stdc++.h>
using namespace std;

void solve(int n,int k){
	int ans=-1;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		if(k % x==0){
			if(ans == -1) ans = x;
			if(ans < x) ans =x;
		}
	}
	cout<<ans<<endl;

}


int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n,k;
		cin>>n>>k;
		solve(n,k);

	}

	return 0;
}