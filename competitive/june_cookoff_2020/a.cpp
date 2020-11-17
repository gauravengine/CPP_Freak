#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,block_size,m;
		cin>>n>>block_size>>m;
		//queue<int> query;
		//query.resize(m);
		
		//cout<<"here";
		ll ans=0;   // ans variable
		int multiple; int size;

		if(n%block_size==0){
			multiple=n/block_size;
			size=n/block_size;
		}
		else{
			multiple=n/block_size;
			size= multiple+1;
		}
		//cout<<"here";
		int *arr= new int[size];
		arr[0]=block_size-1;
		for(int i=1;i<size-1;i++){
			arr[i]=arr[0]+block_size;
			
		}
		arr[size-1]= n-1;
		//for(int i=0;i<size;i++) cout<<arr[i]<<" ";

		//int i=m-1;
		/*
		while(query.size() != 0){
			int q= query.front();
			query.pop();
			int curr= lower_bound(arr,arr+size,q)-arr;
			//cout<<"curr : "<<curr<<endl;
			if(curr != size) ans++;
			
					while( query.front()<=arr[curr]){
						//ans++;
						query.pop();
						
					}
			
			
			if(i+1>m || query[i+1] > arr[curr]){
				i++;
			} 
			//else i--;
			//cout<<i<<endl;			
		} */
		int q_first; cin>>q_first;
		int curr=lower_bound(arr,arr+size,q_first)-arr;
		ans++;
		for(int i=0;i<m-1;i++){
			int q; cin>>q;
			if(q>arr[curr]){
			curr=lower_bound(arr,arr+size,q)-arr;
			ans++;
			}
		}
		cout<<ans<<endl;

	}

	return 0;
}