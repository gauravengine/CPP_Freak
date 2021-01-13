#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int x,y;
        for(int i=0;i<n;i++){
            //cout<<" arr[i] "<<arr[i]<<endl;
            //cout<<(arr[i]-1)<<endl;
            if(arr[abs(arr[i])-1] < 0) y = abs(arr[i]);
            else arr[abs(arr[i])-1]=arr[arr[i]-1]*(-1);
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0) x=i+1;
        }
        
        int *ans= new int[2];
         ans[0]=y; ans[1]=x;
        return ans;    
    }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends