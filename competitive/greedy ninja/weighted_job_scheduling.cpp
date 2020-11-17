#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
struct job{ int start,finish,profit;
};

bool comparator(job a,job b){
	return a.finish < b.finish;
}
int optimizer(int i,int finish[],int x){
	int start=0;
	int end=i-1;
	while(start<=end){
		int mid=(start+end)/2;
		if(finish[mid]>x) end=mid-1;
		if(finish[mid]<x) start=mid+1;
		if(finish[mid]==x) return mid;
	}

	return end;
}

int helper(job arr[],int n,int finish[]){
	int *dp=new int [n];
	dp[0]=arr[0].profit;
	for(int i=1;i<n;i++){
		int inclusive= arr[i].profit;
		int lastindex=optimizer(i,finish,arr[i].start);
		/*
		for(int j=i-1;j>=0;j--){
			if(arr[j].finish <= arr[i].start){
				lastindex=j;
				break;
			}	
			
		} */
		if(lastindex != -1){
				inclusive += dp[lastindex];
			}

			dp[i] =max(inclusive,dp[i-1]);
		

	}

	int ans=dp[n-1];
		delete[] dp;
		return ans;
}

int main(){
	int n; cin>>n;
	job arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
	}
	
	sort(arr,arr+n,comparator);
	int finish[n];
	for(int i=0;i<n;i++){
		finish[i]=arr[i].finish;
	}
	/*
	for(int i=0;i<n;i++){
		cout<<arr[i].start<<" "<<arr[i].finish<<" "<<arr[i].profit;
		cout<<endl;
	} */
	cout<<helper(arr,n,finish)<<endl;



	

	return 0;
}