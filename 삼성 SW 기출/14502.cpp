#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<vector<int>> v;
queue <pair<int, int>> vq;
int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };
int res=0;
int maxV = 0;

void virus() {
	queue<pair<int, int>> temp = vq;
	bool visited[9][9] = { false };
	int cnt = 0;

	while (!temp.empty()) {
		int x = temp.front().first;
		int y = temp.front().second;
		temp.pop();

		for (int dir = 0; dir < 4; dir++) {
			if (x + xd[dir] >= 0 and x + xd[dir] < n and y + yd[dir] >= 0 and y + yd[dir] < m) {
				if (v[x + xd[dir]][y + yd[dir]] == 0 and !visited[x + xd[dir]][y + yd[dir]]) {
					visited[x + xd[dir]][y + yd[dir]] = true; cnt++;
					temp.push({ x + xd[dir],y + yd[dir] });
				}
			}
		}
	}

	int sum = res - 3 - cnt;
	maxV = max(maxV, sum);
}
void findCase(int cnt, int start) {
	if (cnt == 3) {
		virus();
		return;
	}

	for (int idx = start; idx < n * m; idx++) {
		int i = idx / m;
		int j = idx % m;

		if (v[i][j] == 0) {
			v[i][j] = 1;
			findCase(cnt + 1, idx + 1);
			v[i][j] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	v.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				vq.push({ i,j });
			}
			else if (v[i][j] == 0) {
				res++;
			}
		}
	}

	findCase(0,0);

	cout << maxV;
}