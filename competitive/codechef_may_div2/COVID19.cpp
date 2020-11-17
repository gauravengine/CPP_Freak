#include<bits/stdc++.h>
using namespace std;
int  getans(int arr[],int size,int ans[]){
	int i=0; int ans_size=0; 
	while(i<size){ // here if i did i<size-1 it wasn't working ! still dont know why XD
		int count=1;
		while((arr[i+1]-arr[i]<=2 )&& (i<size-1)){
			count++; i++; //cout<<"inside while loop "<<endl;
		}
		i++;
		ans[ans_size]=count;
		ans_size++;
		//cout<<"i is "<<i<<endl;
		//cout<<"outside while loop"<<endl;
	}

return ans_size;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans[11]; int ans_size;
		cin>>n; int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		ans_size=getans(arr,n,ans);
		sort(ans,ans+ans_size);
		//cout<<"ans size :"<<ans_size<<endl;
		if(ans_size==1){
			cout<<ans[0]<<" "<<ans[0]<<endl;
		}
		else cout<<ans[0]<<" "<<ans[ans_size-1]<<endl;


	}

	return 0;
}