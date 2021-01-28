// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


int findPages(int arr[], int n, int m);

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        cout << findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//User function template in C++

bool isvalid(int *arr,int n, int mid, int stu){
    if(stu > n) return false;
    int curr_stu=1;
    int sum= 0;
    for(int i=0;i<n;i++){
        sum+= arr[i];
        if(sum>mid){
            curr_stu++;
            sum= arr[i];
        }
        if(curr_stu > stu) return false;
    }
    return true;
}

int findPages(int *arr, int n, int m) {
    int sum=0,max=INT_MIN;
    for(int i=0;i<n;i++){
        sum+= arr[i];
        if(max<arr[i] ) max= arr[i];
    }
    int low= max; // b/c someone will get this book for sure if i do 0 here isvalid doesnt care this carefully

    int high = sum;

    int ans=-1;
    while(low<=high){
        int mid= low+(high-low)/2;
        cout<<"mid :"<<mid<<" ";
        if(isvalid(arr,n,mid,m)){
            ans=mid;
            cout<<"ans : "<<(ans)<<endl;
            high= mid-1;
        }
        else {
            
            low= mid+1;
        }
        
    }
    return ans;
}

