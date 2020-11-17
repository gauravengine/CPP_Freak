// it worked XD
#include<bits/stdc++.h>
using namespace std;
int main(){
	unordered_map<int,int> base;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		base[i]=i;
	}
	int k=1;
	int sum=0;
	unordered_map<int,int> given;
	for(int i=0;i<n;i++ ){
		int a;
		cin>>a;
		given[a]=abs(k-base[a]);
		k++;
		if(given[a]>2){
			cout<<"NO";
			return 0;
		}
		else{
			sum += given[a];
		}
	}


	cout<<"YES\n"<<sum/2;


	return 0;
}