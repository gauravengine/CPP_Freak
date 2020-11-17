#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000009
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2 !=0){
			//int even=2;
			//int odd=1;
			for(int i=0;i<n*n;i+=n){
				for(int j=i;j<i+n;j++){
					if(j%2 != 0) cout<<j+1<<" ";
					else cout<<j+1<<" ";
				}
				cout<<endl;
			}
		}
		else{
			int even=2;
			int odd=1;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if((i+j)%2==0){
						cout<<odd<<" ";
						odd = odd+2;
					}
					else{
						cout<<even<<" ";
						even= even+2;
					}
				}
				cout<<endl;
			}
		}
	}	
return 0;
}