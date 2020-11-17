#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin>>t;
	while(t--){
		int arr[6];
		for(int i=0;i<6;i++){
			cin>>arr[i];
		}
		int sum=0;
		for(int i=0;i<5;i++){
			arr[i]=arr[i]*arr[5];
			sum+=arr[i];
		}
		if(sum<=120) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;

	}


	return 0;
}