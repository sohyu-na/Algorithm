#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dp[1001][3];
void calc(int k) {
	dp[k][0] += min(dp[k - 1][1], dp[k - 1][2]);
	dp[k][1] += min(dp[k - 1][0], dp[k - 1][2]);
	dp[k][2] += min(dp[k - 1][1], dp[k - 1][0]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			// 입력
			cin >> dp[i][j];
		}
		// 계산
		calc(i);
	}

	int res = min(dp[n - 1][0],dp[n-1][1]);
	res = min(res, dp[n - 1][2]);

	// 출력
	cout << res;
}