#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dp[501][501];
void calc(int n) {
	for (int i = 0; i < n - 1; i++) {
		dp[n - 1][i] += max(dp[n][i], dp[n][i + 1]);
	}
	
	if (n != 1) {
		return calc(n - 1);
	}
	else {
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			// 입력
			cin >> dp[i][j];
		}
	}

	// 계산
	calc(n);

	// 출력
	cout << dp[1][0];
}