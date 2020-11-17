#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*int main() {

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
int arr[n]; ll count=0;
for(int i=0;i<n;i++){
 cin>>arr[i];
}
for(int i=0;i<n;i++){
	sort(arr,arr+i);
	int till_i=lower_bound(arr,arr+i,arr[i])-arr;
	for(int i=0;i<till_i;i++){
		count+=arr[i];
	}


}

cout<<count<<endl;

	}
} */

ll merge(int arr[],int beg,int mid,int end){
	int i=beg; int j=mid; int k=0; int temp[end-beg+1];
	ll count=0;
	while(i<mid&&j<=end){
		if(arr[i]<arr[j]){
			count+=(end-j+1)*arr[i];
				temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
}
while(i<mid){
			temp[k++]=arr[i++];
		}
		while(j<=end){
			temp[k++]=arr[j++];
		}
 for(int m=beg,k=0;m<=end;k++,m++){
 	arr[m]=temp[k];
 }
 return count;
}


ll merge_sort(int arr[],int left ,int right){
	int mid=(left+right)/2; ll count=0;
	if(left<right){
		ll left_count=merge_sort(arr,left,mid);
		ll right_count=merge_sort(arr,mid+1,right);
		ll bymerging=merge(arr,left,mid+1,right);
		return left_count+right_count+bymerging;
	}
	return count;
}

int main()
{
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int arr[n]; ll count=0;
		for(int i=0;i<n;i++){
 			cin>>arr[i];
		}
		count=merge_sort(arr,0,n-1);
		cout<<count<<endl;
	}
}