#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std; 

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> dp(n);
	dp[0] = 1;
	int maxCnt = 1;
	for (int i = 1; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				cnt = max(cnt, dp[j] + 1);
			}
		}
		dp[i] = cnt;
		maxCnt = max(maxCnt, cnt);
	}
	cout << maxCnt;
	return 0;
}