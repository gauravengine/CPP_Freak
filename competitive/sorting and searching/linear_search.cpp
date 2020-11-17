
#include <bits/stdc++.h> 
using namespace std; 
  
int search(int arr[], int n, int x) 
{ 
     
    for (int i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    


    return -1; 
} 
  
int main() 
{ 
    int n; cin>>n;
    int* arr= new int[n];
     for (int i = 0; i < n; i++)  
        cin>>arr[i];
    
    int x; cin>>x;
    int result = search(arr, n, x); 
  

    if (result == -1) 
        cout<<"Element is not present in array" ;
    else
        cout<<"Element is present at index " <<result; 



   return 0; 
} 