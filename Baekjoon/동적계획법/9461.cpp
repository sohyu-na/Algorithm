#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long dp[101];

void calc(int k) {
	for (int i = 6; i <= k; i++) {
		dp[i] = dp[i - 5] + dp[i - 1];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		// 입력
		int k; cin >> k;

		// 계산
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;
		calc(k);

		// 출력 
		cout << dp[k]<<"\n";
	}
}