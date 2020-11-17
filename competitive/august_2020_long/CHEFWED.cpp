// for k=1
#include<bits/stdc++.h>
using namespace std;

bool findprev(int initial,int current,int val,int *arr){
	for(int i=initial;i < current;i++){
		if(arr[i] == val)
			return true;
	}

	return false;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		
		int n,k; 
		cin>>n>>k;
		int* arr= new int[n];
		unordered_map<int,int> freq;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			freq[arr[i]] ++ ;
		}
		int table=1,initial=0; // initial address and tables
		for(int i=0;i<n;i++){
			if(freq[arr[i]]>1){
				if( findprev(initial,i,arr[i] ,arr) ){
					initial=i;
					table++;
					freq[arr[i]] --;
				}
			}
		}
		cout<<table<<"\n";

	}

	return 0;
}