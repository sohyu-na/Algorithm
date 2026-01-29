#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[10001];
int dp[10001];

void calc(int n) {
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[2], arr[1] + arr[3]);
	dp[3] = max(dp[3], arr[2] + arr[3]);

	for (int i =4; i <= n; i++) {
		dp[i] = max(dp[i - 2]+arr[i], dp[i - 3] + arr[i-1]+arr[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		// 입력
		cin >> arr[i];
	}
	// 계산
	calc(n);

	// 출력
	cout << dp[n];
}