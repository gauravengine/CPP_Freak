#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, i;
		cin >> n;
		vector<int> a(n);
		for (i = 0; i < n; i++)
			cin >> a[i];
		//Handle Edge Cases
		if (n == 1)
			cout << "0\n";
		else if (n == 2) {
			if (a[0] != a[1])
				cout << "0\n";
			else
				cout << "-1\n";
		}
		else if (n == 3) {
			vector<tuple<int, int, int>> ops;
			bool poss = true;
			if (!a[1] && a[0])
				ops.push_back({1, 2, 3});
			else if (!a[1] && a[2])
				ops.push_back({2, 3, 1});
			else if (a[0] != a[2] || (a[0] == a[1] && a[1] == a[2] && a[0] == 0)) {
				cout << "-1\n";
				poss = false;
			}
			else if (a[1] == a[2])
				ops.push_back({1, 3, 2});
			if (poss) {
				int m = ops.size();
				cout << m << "\n";
				for (auto [x, y, z] : ops)
					cout << x << " " << y << " " << z << "\n";
			}
		}
		//N greater than equal to 4
		else {
			//Check all zeros - impossible
			if (count(a.begin(), a.end(), 0) == n)
				cout << "-1\n";
			else {
				set<int> even, odd;
				//Add odd elements into set
				for (i = 1; i < n; i += 2)
					odd.insert(a[i]);
				//Add even elements into set
				for (i = 0; i < n; i += 2)
					even.insert(a[i]);
				if (odd.size() == 1 && even.size() == 1) {
					if (*odd.begin() != *even.begin())
						cout << "0\n";
					else {
						vector<tuple<int, int, int>> ops;
						for (i = 1; i < n; i += 2)
							ops.push_back({1, 3, i + 1});
						int m = ops.size();
						cout << m << "\n";
						for (auto [x, y, z] : ops)
							cout << x << " " << y << " " << z << "\n";
					}
				}
				else {
					vector<tuple<int, int, int>> ops;
					//Find two positions of same parity having different values
					//Checking even positions first
					int fs1 = a[0], sc1 = -1;
					for (i = 2; i < n; i += 2) {
						if (a[i] != fs1) {
							sc1 = i;
							break;
						}
					}
					//No different even index elements were found
					if (sc1 == -1) {
						int fs2 = a[1], sc2 = -1;
						for (i = 3; i < n; i += 2) {
							if (a[i] != fs2) {
								sc2 = i;
								break;
							}
						}
						//Odd pair found 1 and sc2
						for (i = 0; i < n; i += 2)
							ops.push_back({2, sc2 + 1, i + 1});
						for (i = 1; i < n; i += 2)
							ops.push_back({1, 3, i + 1});
						int m = ops.size();
						cout << m << "\n";
						for (auto [x, y, z] : ops)
							cout << x << " " << y << " " << z << "\n";
					}
					else {
						//Even pair found 0 and sc1
						for (i = 1; i < n; i += 2)
							ops.push_back({1, sc1 + 1, i + 1});
						for (i = 0; i < n; i += 2)
							ops.push_back({2, 4, i + 1});
						int m = ops.size();
						cout << m << "\n";
						for (auto [x, y, z] : ops)
							cout << x << " " << y << " " << z << "\n";

					}
				}
			}

		}
	}

	return 0;
}