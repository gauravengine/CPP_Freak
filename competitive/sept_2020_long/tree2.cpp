#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		unordered_map<int,int> freq;
		int count=0;
		int n; cin>>n;
		//int* arr= new int[n];
		for(int i=0;i<n;i++){
			int x; cin>>x;
			if(x==0 ) continue;
			if(freq[x]== 0) {
				count++;
				freq[x]++;
			}
		}



		cout<<count<<endl;

	}

	return 0;
}