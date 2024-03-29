
#include <bits/stdc++.h> 
using namespace std; 

int binary(int arr[], int l, int r, int x) 
{ 
	if (r >= l) { 
		
		int mid = l + (r - l) / 2; 

		if (arr[mid] == x) 
			return mid; 

	
		if (arr[mid] > x) 
			return binary(arr, l, mid - 1, x); 

		 
		return binary(arr, mid + 1, r, x); 
	} 

	
	return -1; 
} 

int main(void) 
{ 
	int n; cin>>n;
    int* arr= new int[n];
     for (int i = 0; i < n; i++)  
        cin>>arr[i];
    
    int x; cin>>x;
	int result = binary(arr, 0, n - 1, x); 

    if (result == -1) 
        cout<<"Element is not present in array" ;
    else
        cout<<"Element is present at index " <<result; 

	
} 
