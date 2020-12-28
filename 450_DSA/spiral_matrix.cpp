
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> m, int r, int c)
    {
        vector<int> output;
        int t=0,b=r-1,l=0,right=c-1;
        int dir=0;
        while(t<=b && l<=right){
            if(dir == 0){
                // l->r
                for(int i=l;i<=right;i++) output.push_back(m[t][i]);
                t++;
                

            }
            else if(dir == 1){
                for(int i=t;i<=b;i++) output.push_back(m[i][right]);
                right--;
                
            }
            else if(dir == 2){
                for(int i=right;i>=l;i--) output.push_back(m[b][i]);
                b--;
                
            }
            else if(dir == 3){
                for(int i=b;i>=t;i--) output.push_back(m[i][l]);
                l++;
                
            }
            dir= (dir+1)%4;
        }
        
        return output;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends