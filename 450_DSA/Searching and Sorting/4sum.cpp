#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
      //  cout<<"mp";
        vector<vector<int> > ans = fourSum(a, k);
      //  cout<<"uff";
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
    int n= arr.size();
    map<vector<int>,bool> hash;
    vector<vector<int> > result;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-4;i++){
        for(int j=i+1;j<n-3;j++){
            
            int l= j+1,r=n-1;
            while(l<r){
                if(arr[i]+arr[j]+arr[l]+arr[r] ==k){
                    vector<int> temp;
                    
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[l]);
                    temp.push_back(arr[r]);
                    if(hash[temp]==false){
                        result.push_back(temp);
                    }
                    hash[temp]=true;
                    l++; r++;
                }
                else if(arr[i]+arr[j]+arr[l]+arr[r] >k){
                    r--;
                }
                else l++;
            }
        }
        
    }
    return result;
}