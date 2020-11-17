#include <bits/stdc++.h> 
using namespace std; 
  

void insertionSort(int arr[], int n)  
{  
    int i, x, j;  
    for (i = 1; i < n; i++) 
    {  
        x = arr[i];  
        j = i - 1;  
  
        
        while (j >= 0 && arr[j] > x) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = x;  
    }  
}  
  


int main()  
{  int n; cin>>n; 
    int* arr= new int[n];
     for (int i = 0; i < n; i++)  
        cin>>arr[i];
  
    insertionSort(arr, n);  
    cout<<"Sorted Array :"<<endl;
     for (int i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
  
    return 0;  
}  
