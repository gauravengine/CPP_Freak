#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin>>n;
	int* arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,greater<int>());
	ll ans=0;
	int j=0;
	for(int i=0;i<n;i++){
		ans += pow(2,j) * arr[i];
		j++;
	}
	cout<<ans<<endl;

	return 0;
}