#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int dp[100][100][100];
int w(int a, int b, int c) {
	if (a <= 0 or b <= 0 or c <= 0) {
		return 1;
	}
	else if (a > 20 or b > 20 or c > 20) {
		return w(20, 20, 20);
	}
	else {
		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= b; j++) {
				dp[i][j][0] = 1;
			}
		}
		for (int i = 0; i <= b; i++) {
			for (int j = 0; j <= c; j++) {
				dp[0][i][j] = 1;
			}
		}
		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= c; j++) {
				dp[i][0][j] = 1;
			}
		}
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				for (int k = 1; k <= c; k++) {
					if (i < j and j < k) {
						dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
					}
					else {
						dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
					}
				}
			}
		}
		return dp[a][b][c];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		// 입력
		int a, b, c; cin >> a >> b >> c;
		if (a == -1 and b == -1 and c == -1) {
			break;
		}
		// 계산 
		int res = w(a, b, c);

		// 출력 
		cout << "w(" << a << ", " << b << ", " << c << ") = " << res<<"\n";
	}
}