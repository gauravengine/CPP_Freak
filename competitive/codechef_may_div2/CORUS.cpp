// done
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		int q; cin>>q;
		cin>>s;
		unordered_map<char,int> freq;
		
			for(int i=0;i<n;i++){
				freq[s[i]]++;
			}
		
		while(q--){
			int c;
			cin>>c;
			unordered_map<char,int> local_freq;
			local_freq=freq;
			int count=0;
			for(char i='a';i<='z';i++){
				/*if(freq[i]-c<0){
					freq[i]=0;
				}
				else freq[i]=freq[i]-c; */
				local_freq[i]=max(0,local_freq[i]-c);
					count+= local_freq[i];						
			}
			
			
			cout<<count<<"\n";

		}


	}


	return 0;
}