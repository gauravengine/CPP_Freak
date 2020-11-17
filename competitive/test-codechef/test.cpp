#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin>>t;
	while(t--){
		ll size; cin>>size;
        ll* a=new ll[size];
        ll* b=new ll[size];
		//ll a[size],b[size];
		ll asum=0,bsum=0,ans=0;
		for(int i=0;i<size;i++){
			cin>>a[i];
		}
		for(int i=0;i<size;i++){
			cin>>b[i];
		}
		for(int i=0;i<size;i++){
			if(asum==bsum && a[i]==b[i]){
				ans+= a[i];
			}
			asum+=a[i]; 
			bsum+=b[i];
		}

		cout<<ans<<endl;
	}


	return 0;
}
