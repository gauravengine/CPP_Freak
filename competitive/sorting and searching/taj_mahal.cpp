#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	 int ans; ; int i=0; int j=0;

	while(arr[j]-i>0){
		
		if(j==n-1) {  j=0;     }
		else j++;
		i++;
	}
	ans=j;
	cout<<ans+1<<endl;
}