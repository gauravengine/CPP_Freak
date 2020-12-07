#include <iostream>
using namespace std;

void solve(int* arr , int low,int high){
    if(low<= high && low>=0 && high >=0){
    int mid= (low+ high)/2;
    cout<<arr[mid]<<" ";
    solve(arr,low,mid-1);
    solve(arr,mid+1,high);

    }    
    else return ;
}
int main() {
	
	
	int t; cin>>t;
	while(t--){
	    int n; cin>>n; 
        int* arr= new int[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
        //cout<<"hello";
	    solve(arr,0,n-1);
        cout<<endl;
	}
	return 0;
}