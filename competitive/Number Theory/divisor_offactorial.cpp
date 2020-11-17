#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mod  1e9+7
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=50001;
	bool* sieve= new bool[n+1];
	sieve[0]=false;
	sieve[1]=false;
	for(int i=2;i<= n;i++){
		sieve[i]= true;
	}
	for(int i=2;i*i<=n;i++){
		if(sieve[i]==true){
			int temp=i;
			for(int j= i*i;j<=n;j=(i*temp)){
				sieve[j]= false;
				temp++;
			}


		}

	}

	int t; cin>>t;
	while(t--){
		ll ans=1;
		int x; cin>>x;
		for(int i=2;i<n;i++){
			if(sieve[i]){
				int power=0;
				for(int j=1; pow(i,j) <= x;j++ ){
					power+= x/pow(i,j);
					
			}
			ans*= (power+1);
				}

		}


	}


	return 0;
}