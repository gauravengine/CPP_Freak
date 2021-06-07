#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	//cout<<"hi";
	vector<vector<int>> closest(n,vector<int> (30,-1));
	for (int i = n - 1; i >= 0; i--) {
		int curr = arr[i];
		if (i < n - 1) closest[i] = closest[i + 1];
		for (int j = 0; j < 30; j++) {
			if (curr & (1 << j) ) {
				closest[i][j] = i;

			}
		}
	}
	
	
	vector<int> dp(n,0);
	for (int i = 0; i < n; i++) {
		//priority_queue<int,vector<int>,greater<int> > pq;
		for (int j = 0; j < 30; j++) {
			if (closest[i][j] != -1 ) {
				dp[i]+=(n-i)*pow(2^j);
				
			}
		}
		// for (int j = 0; j < 30; j++) {
		// 	if (closest[i][j] != -1 && closest[i][j] != i) {
		// 		pq.push(closest[i][j]);
				
		// 	}
		// }
		// int curr_or = arr[i];
		// int last_i = i;

		
		// while (!pq.empty()) {
		// 	int curr_i = pq.top();
		// 	pq.pop();
		// 	dp[i] += (curr_i - last_i) * curr_or;
		// 	curr_or = curr_or | arr[curr_i];
		// 	last_i = curr_i;
		// }
		// dp[i] += (n - last_i) * curr_or;

	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += dp[i];
		
	}
	cout << ans;
}