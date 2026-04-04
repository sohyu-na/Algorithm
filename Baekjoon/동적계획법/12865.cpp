#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> dp(k + 1, 0); // 무게 한도 w일 때 얻을 수 있는 최대 가치

	int w, v;
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		for (int i = k; i >= w; i--) {
			// w를 넣을 수있는 무게i에 대해 dp[i-w]+v 와 dp[i] 중 max값 갱신
			dp[i] = max(dp[i], dp[i - w] + v);
		}
	}
	cout << dp[k];
	return 0;
}