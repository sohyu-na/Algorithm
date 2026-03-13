#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> v;
int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };
int maxSum = 0;
bool visited[501][501] = { false };

void dfs(int i, int j, int cnt, int sum) {
	visited[i][j] = true;
	
	if (cnt == 4) {
		if (maxSum < sum) {
			maxSum = sum; 
		}
		visited[i][j] = false;
		return ;
	}
	//방향 탐색
	for (int dir = 0; dir < 4; dir++) {
		if (i + xd[dir] >= 0 and i + xd[dir] < n and j + yd[dir] >= 0 and j + yd[dir] < m and !visited[i + xd[dir]][j + yd[dir]]) {
			dfs(i + xd[dir], j + yd[dir], cnt + 1, sum + v[i + xd[dir]][j + yd[dir]]);
		}
	}
	visited[i][j] = false;
	return;
}
void ohCheck(int i, int j) {
	int sum = v[i][j];
	int cnt = 0;
	int minV = 1e9;

	for (int dir = 0; dir < 4; dir++) {
		if (i + xd[dir] >= 0 and i + xd[dir] < n and j + yd[dir] >= 0 and j + yd[dir] < m) {
			cnt++;
			sum += v[i + xd[dir]][j + yd[dir]];
			minV = min(minV, v[i + xd[dir]][j + yd[dir]]);
		}
	}
	if (cnt == 4) {
		sum -= minV;
	}
	if (cnt >= 3) {
		maxSum = max(maxSum, sum);
	}
}
int main() {
	cin >> n >> m;
	v.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, 1,v[i][j]);
			ohCheck(i, j);
		}
	}
	cout << maxSum;
}