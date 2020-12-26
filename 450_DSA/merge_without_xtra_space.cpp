#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
    void merge(int x[], int y[], int n, int m)
    {
        // consider each element X[i] of array X and ignore the element
        // if it is already in correct order else swap it with next smaller
        // element which happens to be first element of Y
        for (int gap = n + m / 2; gap >= 1; gap = gap / 2)
        {
            for (int i = 0; i < n + m -gap; i++)
            {
                int j = i + gap;
                if (i < n && j < n)
                {
                    if (x[i] > x[j])
                    {
                        swap(x[i], x[j]);
                        if (i - gap >= 0 && x[i] < x[i - gap])
                        {
                            swap(x[i], x[i - gap]);
                        }
                    }
                    continue;
                }

                if (i < n && j >= n && j < n + m)
                {
                    if (x[i] > y[j - n])
                    {
                        swap(x[i], y[j - n]);
                        if (i - gap >= 0 && x[i] < x[i - gap])
                        {
                            swap(x[i], x[i - gap]);
                        }
                    }
                    continue;
                }

                if (i >= n && j > n && j < n + m)
                {
                    if (y[i - n] > y[j - n])
                    {
                        swap(y[i - n], y[j - n]);
                        if (i - gap >= n)
                        {
                            if (y[i - n] < y[i - gap - n])
                            {
                                swap(y[i - n], y[i - gap - n]);
                            }
                        }
                        if (i - gap < n && i - gap >= 0)
                        {
                            if (y[i - n] < x[i - gap])
                            {
                                swap(y[i - n], x[i - gap]);
                            }
                        }
                    }
                    continue;
                }

                if (j >= n + m)
                {
                    break;
                }
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends