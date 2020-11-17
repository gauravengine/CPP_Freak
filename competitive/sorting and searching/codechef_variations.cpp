#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k; int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	sort(arr,arr+n);
	int total_variation_count=0;
	for(int i=0;i<n;i++){
		int just_next;
		just_next=lower_bound(arr,arr+n,arr[i]+k)-arr;
		total_variation_count += (n-just_next);
	}
	cout<<total_variation_count<<endl;
}