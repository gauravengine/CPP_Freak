//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends

//User function template for C++

// int qs(int prev, int end, vector<int> &arr, int pivot)
// {
//     int i = prev - 1;
//     for (int j = prev; j <= end; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[j], arr[i]);
//         }
//     }
//     // swap arr[i+1] wid pivot pos;
//     for (int x = prev; x <= end; x++)
//     {
//         if (arr[x] == pivot)
//             swap(arr[i + 1], arr[x]);
//     }
    

    
//     return i + 1;
// }

class Solution
{
public:
    void threeWayPartition(vector<int> &arr, int lowVal, int highVal)
    {
        // dutch 3 flag based quick sort
        int start = 0, end = arr.size() - 1;

        // Traverse elements from left
        for (int i = 0; i <= end;)
        {
            if (arr[i] < lowVal)
                swap(arr[i++], arr[start++]);

            else if (arr[i] > highVal)
                swap(arr[i], arr[end--]);

            else
                i++;
        }
        for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        vector<int> array(N);
        unordered_map<int, int> ump;

        for (int i = 0; i < N; i++)
        {
            cin >> array[i];
            ump[array[i]]++;
        }

        int a, b;
        cin >> a >> b;

        vector<int> original = array;

        int k1 = 0, k2 = 0, k3 = 0;
        int kk1 = 0;
        int kk2 = 0;
        int kk3 = 0;

        for (int i = 0; i < N; i++)
        {
            if (original[i] > b)
                k3++;
            else if (original[i] <= b and original[i] >= a)
                k2++;
            else if (original[i] < b)
                k1++;
        }

        Solution ob;
        ob.threeWayPartition(array, a, b);
        
        for (int i = 0; i < k1; i++)
        {
            if (array[i] < b)
                kk1++;
        }

        for (int i = k1; i < k1 + k2; i++)
        {
            if (array[i] <= b and array[i] >= a)
                kk2++;
        }

        for (int i = k1 + k2; i < k1 + k2 + k3; i++)
        {
            if (array[i] > b)
                kk3++;
        }
        bool ok = 0;
        if (k1 == kk1 and k2 == kk2 and k3 == kk3)
            ok = 1;

        for (int i = 0; i < array.size(); i++)
            ump[array[i]]--;

        for (int i = 0; i < array.size(); i++)
            if (ump[array[i]] != 0)
                ok = 0;

        if (ok)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends
