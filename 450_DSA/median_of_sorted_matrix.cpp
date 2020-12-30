// C++ program to find median of a matrix
// sorted row wise
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// function to find median in the matrix
int binaryMedian(int m[][MAX], int r, int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];

        // Finding the maximum element
        if (m[i][c - 1] > max)
            max = m[i][c - 1];
    }

    int desired = (r * c + 1) / 2;
    cout<<desired<<endl;
    while (min < max)
    { cout<<endl<<"min : "<<min <<" max : "<<max<<endl;
        /*1 3 4
          2 7 9
          3 7 11 */
        //  1 2 3 3 5 7 7 9 11
        int mid = min + (max - min) / 2;
        cout<<"mid :" <<mid<<endl;
        int place = 0;

        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i){
           // cout << upper_bound(m[i], m[i] + c, mid)<<endl;
          //  cout<<m[i]<<endl;
            place += upper_bound(m[i], m[i] + c, mid) - m[i];
            
        }    
        cout<<"place : "<<place<<endl;
        /*
        will this work?
        if(place== desired) return mid
        and
        if(place <=desired) min = mid;
        else max= mid-1;
        will try on gfg ;-)
        nope didnt worked
        */
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    cout<<endl<<"ans is :"<<min<<endl;
    return min;
}

// driver program to check above functions
int main()
{
    int r = 3, c = 3;
    int m[][MAX] = {{1, 3, 3}, {2, 7, 9}, {3, 7, 11}};
    binaryMedian(m, r, c);
    return 0;
}
