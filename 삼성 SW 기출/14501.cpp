#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n; cin >> n;

	vector<pair<int, int>> v;
	int t, p;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		v.push_back({ t,p });
	}
	int dp[20] = { 0 };
	for (int i = n - 1; i >= 0; i--) {
		if (i + v[i].first <= n) {
			dp[i] = max(v[i].second + dp[i + v[i].first], dp[i + 1]);
		}
		else {
			dp[i] = dp[i + 1];
		}
	}
	cout << dp[0];
}