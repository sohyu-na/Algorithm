#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std; 

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

struct info {
	int x, y, cnt;
};
int main() {
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 9) {
				sx = i; sy = j;
				v[sx][sy] = 0;
			}
		}
	}

	int sharkSize = 2;
	int moveCnt = 0;
	int eatCnt = 0;

	while (true) {
		queue<info> q; q.push({ sx,sy,0 });
		vector<vector<bool>> check(n, vector<bool>(n, false));
		check[sx][sy] = true;

		int minCnt = INT_MAX;
		int fx = INT_MAX, fy = INT_MAX;

		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int cnt = q.front().cnt;
			q.pop();
			if (cnt >= minCnt) break;

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + xd[dir];
				int ny = y + yd[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (check[nx][ny]) continue;
				if (v[nx][ny] > sharkSize) continue;

				check[nx][ny] = true;
				if (v[nx][ny] >0 && v[nx][ny] < sharkSize) {
					minCnt = cnt+1;
					if (nx < fx || (nx==fx && ny<fy)) {
						fx = nx;
						fy = ny;
					}
				}
				q.push({ nx,ny,cnt + 1 });
			}
			
		}
		if (fx == INT_MAX) break;

		moveCnt += minCnt; eatCnt++;
		v[fx][fy] = 0;
		sx = fx; sy = fy;
		if (eatCnt == sharkSize) {
			sharkSize++;
			eatCnt = 0;
		}
	}
	cout << moveCnt;
	return 0;
}

	