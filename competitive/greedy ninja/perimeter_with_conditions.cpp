#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n; cin>>n;
	int* arr= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=n-1;i>1;i--){
		int l=i-2; int r=i-1;
		if(arr[l]+arr[r]>arr[i]){
			cout<<arr[i-2]<<" "<<arr[r]<<" "<<arr[i];
			return 0;
		}
	}
	cout<<-1;
	
	return 0;
}