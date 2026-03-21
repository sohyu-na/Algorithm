#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m, h;
bool ladder[11][31] = { false };

bool equalLine(bool v[11][31]) {
	bool result = true;
	for (int i = 1; i <= n; i++) {
		int now = i;
		for (int j = 1; j <= h; j++) {
			if (v[now][j] == true) {
				now += 1;
			}
			else if (now - 1 >= 1 and v[now - 1][j] == true) {
				now -= 1;
			}
		}
		if (i != now) {
			result = false;
			break;
		}
	}
	return result;
}
bool dfs(int idx, int cnt, int target) {
	if (cnt == target) return equalLine(ladder);

	for (int k = idx; k < (n - 1) * h; k++) {
		int i = k / h + 1;
		int j = k % h + 1;

		if (ladder[i][j]) continue; //이미
		if (i > 1 and ladder[i - 1][j]) continue; // 왼쪽 겹침
		if (i < n - 1 and ladder[i + 1][j]) continue; //오른쪽 겹침

		ladder[i][j] = true;
		if (dfs(k + 1, cnt + 1, target)) { 
			ladder[i][j] = false; 
			return true; 
		}
		ladder[i][j] = false;
	}
	return false;
}
int main() {
	cin >> n >> m >> h;

	int row, col;
	for (int i = 0; i < m; i++) {
		cin >> col >> row;
		ladder[row][col] = true;
	}
	if (dfs(0, 0, 0)) cout << "0";
	else if (dfs(0, 0, 1)) cout << "1";
	else if (dfs(0, 0, 2)) cout << "2";
	else if (dfs(0, 0, 3)) cout << "3";
	else cout << "-1";

	return 0;
}