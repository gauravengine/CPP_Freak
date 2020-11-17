#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
 int p=*a;
 *a=*b;
 *b=p;
}


int partition(int arr[],int low,int high ){
	int i=low-1;
	int j=low;
	for(;j<=high-1;j++){
		if(arr[j]<arr[high]){
			i++;
			swap(&arr[i],&arr[j]);
		}

	}
	swap(&arr[i+1],&arr[high]);
	return i+1;

}

void quicksort(int arr[],int low,int high){
	if(low<high){
		//pi is the middle element that is in right place
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}

}
void print(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
   int n;
   vector<int> test;
   test.push_back(4);
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
   	cin>>arr[i];

   }
   quicksort(arr,0,n-1);
   print(arr,n);
    return 0;
}