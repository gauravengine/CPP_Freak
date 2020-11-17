#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	ll* arr=new ll[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll energy=0; ll i=0; //int next;
	while(i<n-1){
		ll j=i+1;
		while(j<n-1){
			if( (abs(arr[i]) > abs(arr[j])) || (abs(arr[i])==abs(arr[j]) && arr[i]>0 ) ){
				//i=j;
				break;
			}
			else {j++; }
		}
		
		energy += (j-i)*arr[i] + (j*j - i*i)*arr[i]*arr[i]; 
		
		i=j;
		}
cout<<energy<<endl;


	return 0;
}