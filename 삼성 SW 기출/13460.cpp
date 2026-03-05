#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<string> v;
struct state {
	int rx, ry, bx, by, cnt;
};
bool check[11][11][11][11];

int xd[4] = { 0,0,-1,1 };
int yd[4] = { 1,-1,0,0 };

struct R {
	int x, y;
	int steps;
	bool fall;
};

R roll(int x, int y, int dir) {
	int steps = 0;
	while (true) {
		if (v[x + xd[dir]][y + yd[dir]] == '.') {
			x += xd[dir];
			y += yd[dir];
			steps++;
		}
		else if (v[x + xd[dir]][y + yd[dir]] == 'O') {
			R r = { x + xd[dir],y + yd[dir],steps+1,true };
			return r;
		}
		else {
			break; //반복문 종료 
		}
	}
	return { x, y, steps, false };
}

int main() {
	int n, m;
	cin >> n>>m;

	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'R') {
				rx = i; ry = j; v[i][j] = '.';
			}
			if (v[i][j] == 'B') {
				bx = i; by = j; v[i][j] = '.';
			}
		}
	}
	queue<state> q;
	q.push({ rx, ry, bx, by,0 });
	check[rx][ry][bx][by] = true;

	while (!q.empty()) {
		state s = q.front(); q.pop();
		if (s.cnt >= 10) continue;

		for (int i = 0; i < 4; i++) {
			R rr = roll(s.rx, s.ry, i); 
			R rb = roll(s.bx, s.by, i);

			if (rb.fall) continue;
			if (rr.fall) {
				cout << s.cnt + 1;
				return 0;
			}

			if (rr.x == rb.x and rr.y == rb.y) {
				if (rr.steps > rb.steps) {
					rr.x -= xd[i];
					rr.y -= yd[i];
				}
				else {
					rb.x -= xd[i];
					rb.y -= yd[i];
				}
			}
			if (!check[rr.x][rr.y][rb.x][rb.y]) {
				check[rr.x][rr.y][rb.x][rb.y] = true;
				q.push({ rr.x, rr.y, rb.x, rb.y, s.cnt + 1 });
			}
		}
	}
	cout << -1;
	return 0;
}