#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool board[101][101] = { false };

int xd[4] = {1,0,-1,0};
int yd[4] = { 0,-1,0,1 };

int main() {
	int n; cin >> n;
	int x, y, d, g;
	for (int i = 0; i < n; i++) {
		queue<pair<int, int>> q;
		deque<int> dir;
		cin >> x >> y >> d >> g;
		board[x][y] = true;
		if (g >= 0) {//->0
			x += xd[d]; y += yd[d];
			board[x][y] = true;
			dir.push_back(d);
		}
		while (g >= 1) {
			deque<int> temp = dir;
			while (!temp.empty()) {
				int d = temp.back();
				temp.pop_back();
				d = (d + 1) % 4;
				x += xd[d]; y += yd[d];
				board[x][y] = true;
				dir.push_back(d);
			}
			g--;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] and board[i + 1][j] and board[i + 1][j + 1] and board[i][j + 1]) cnt++;
		}
	}
	cout << cnt;
}

	