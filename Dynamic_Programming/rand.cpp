#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int countZero = 0;
    int countOne = 1;
    int countTwo = 2;

    for (int i = 0; i < 100000; i++) {
        int x = rand() % 3;
        switch (x)
        {
        case 0:
        {
            countZero++;
            break;
        }
        case 1:
        {
            countOne++;
            break;
        }
        default:
        {
            countTwo++;
            break;
        }

        }
    }

    cout << (float)countZero / 100000 << '\n';
    cout << (float)countOne / 100000 << '\n';
    cout << (float)countTwo / 100000 << '\n';
}