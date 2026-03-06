#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<string> v;
bool check[11][11][11][11];

struct State {
	int rx, ry, bx, by, cnt;
};

int xd[4] = { 0,0,-1,1 };
int yd[4] = { 1,-1,0,0 };

struct resultRoll {
	int x, y;
	int steps;
	bool fall;
};
resultRoll roll(int x, int y, int dir) {
	int steps = 0;
	while (true) {
		if (v[x + xd[dir]][y + yd[dir]] == '#') break;
		else if (v[x + xd[dir]][y + yd[dir]] == '.') {
			x += xd[dir];
			y += yd[dir];
			steps++;
		}
		else if (v[x + xd[dir]][y + yd[dir]] == 'O') {
			return resultRoll{ x + xd[dir], y + yd[dir],steps, true };
		}
	}
	return resultRoll{x, y, steps, false};
}

int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'R') { rx = i; ry = j; v[i][j] = '.'; }
			if (v[i][j] == 'B') { bx = i; by = j; v[i][j] = '.'; }
		}
	}

	queue<State> q;
	q.push({ rx,ry,bx,by,0 });
	check[rx][ry][bx][by] = true;

	while (!q.empty()) {
		auto s = q.front(); q.pop();
		if (s.cnt >=10) continue;

		for (int dir = 0; dir < 4; dir++) {
			auto R = roll(s.rx, s.ry, dir);
			auto B=roll(s.bx, s.by, dir);

			if (B.fall) continue;
			if (R.fall) {
				cout << s.cnt + 1;
				return 0;
			}

			if (R.x == B.x and R.y == B.y) {
				if (R.steps > B.steps) { R.x -= xd[dir]; R.y -= yd[dir]; }
				else{ B.x -= xd[dir]; B.y -= yd[dir]; }
			}

			if (!check[R.x][R.y][B.x][B.y]) {
				check[R.x][R.y][B.x][B.y] = true;
				q.push({ R.x,R.y,B.x,B.y,s.cnt + 1 });
			}
		}
	}
	cout << "-1";
	return 0;

}