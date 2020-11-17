#include<bits/stdc++.h>
using namespace std;
int main() {

	int n;
    int I,k;
    cin>>n>>k>>I;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cost=INT_MAX;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
    	int pivot=arr[i];
    	int increase=0,decrease=0;
    	for(int j=0;j<n;j++){
    		if(arr[j]>pivot) 
    			decrease += arr[j]-pivot;
    		else
    			increase += pivot-arr[j]; 
    	}

    	// i got inc dec now
    	if( increase >= decrease){
    		int curr_cost= (decrease)* k + (increase-decrease) * I;
    		if(curr_cost<cost) cost=curr_cost;
    	}



    }

    
    cout<<cost;
    
    return 0;
}