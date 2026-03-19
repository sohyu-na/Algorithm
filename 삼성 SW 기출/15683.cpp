#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m; 	
int result = 0;

void dfs(vector<vector<int>> v, queue <pair<int, int>> q) {
	if (q.empty()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == -1) cnt++;
			}
		}
		result = max(result, cnt);
		return;
	}

	int x = q.front().first;
	int y = q.front().second;
	q.pop();
	
	if (v[x][y] == 1) {
		vector<vector<int>> v1 = v;
		for (int i = x; i >= 0; i--) { //위
			if (v1[i][y] == 0) v1[i][y] = -1;
			else if (v1[i][y] == 6) break;
		}
		dfs(v1,q);

		vector<vector<int>> v2 = v;
		for (int i = x; i < n; i++) { //아래
			if (v2[i][y] == 0) v2[i][y] = -1;
			else if (v2[i][y] == 6) break;
		}
		dfs(v2, q);

		vector<vector<int>> v3 = v;
		for (int j = y; j >= 0; j--) { //왼
			if (v3[x][j] == 0)v3[x][j] = -1;
			else if (v3[x][j] == 6) break;
		}
		dfs(v3, q);

		vector<vector<int>> v4 = v;
		for (int j = y; j < m; j++) { //오
			if (v4[x][j] == 0) v4[x][j] = -1;
			else if (v4[x][j] == 6) break;
		}
		dfs(v4, q);
	}
	else if (v[x][y] == 2) {
		vector<vector<int>> v1 = v;
		for (int i = x; i >= 0; i--) {
			if (v1[i][y] == 0) v1[i][y] = -1;
			else if (v1[i][y] == 6) break;
		}
		for (int i = x; i < n; i++) {
			if (v1[i][y] == 0) v1[i][y] = -1;
			else if (v1[i][y] == 6) break;
		}
		dfs(v1, q);

		vector<vector<int>> v3 = v;
		for (int j = y; j >= 0; j--) {
			if (v3[x][j] == 0)v3[x][j] = -1;
			else if (v3[x][j] == 6) break;
		}
		for (int j = y; j < m; j++) {
			if (v3[x][j] == 0) v3[x][j] = -1;
			else if (v3[x][j] == 6) break;
		}
		dfs(v3, q);
		
	}
	else if (v[x][y] == 3) {
		vector<vector<int>> v1 = v;
		for (int i = x; i >= 0; i--) { //위
			if (v1[i][y] == 0) v1[i][y] = -1;
			else if (v1[i][y] == 6) break;
		}
		for (int j = y; j >= 0; j--) { //왼
			if (v1[x][j] == 0)v1[x][j] = -1;
			else if (v1[x][j] == 6) break;
		}
		dfs(v1, q);

		vector<vector<int>> v2 = v;
		for (int i = x; i < n; i++) { //아래
			if (v2[i][y] == 0) v2[i][y] = -1;
			else if (v2[i][y] == 6) break;
		}
		for (int j = y; j < m; j++) { //오
			if (v2[x][j] == 0) v2[x][j] = -1;
			else if (v2[x][j] == 6) break;
		}
		dfs(v2, q);

		vector<vector<int>> v3 = v;
		for (int j = y; j >= 0; j--) { //왼
			if (v3[x][j] == 0)v3[x][j] = -1;
			else if (v3[x][j] == 6) break;
		}
		for (int i = x; i < n; i++) { //아래
			if (v3[i][y] == 0) v3[i][y] = -1;
			else if (v3[i][y] == 6) break;
		}
		dfs(v3, q);

		vector<vector<int>> v4 = v;
		for (int j = y; j < m; j++) { //오
			if (v4[x][j] == 0) v4[x][j] = -1;
			else if (v4[x][j] == 6) break;
		}
		for (int i = x; i >= 0; i--) { //위
			if (v4[i][y] == 0) v4[i][y] = -1;
			else if (v4[i][y] == 6) break;
		}
		dfs(v4, q);
	}
	else if (v[x][y] == 4) {
		vector<vector<int>> v1 = v;
		for (int i = x; i >= 0; i--) { //위
			if (v1[i][y] == 0) v1[i][y] = -1;
			else if (v1[i][y] == 6) break;
		}
		for (int j = y; j >= 0; j--) { //왼
			if (v1[x][j] == 0)v1[x][j] = -1;
			else if (v1[x][j] == 6) break;
		}
		for (int i = x; i < n; i++) { //아래
			if (v1[i][y] == 0) v1[i][y] = -1;
			else if (v1[i][y] == 6) break;
		}
		dfs(v1, q);

		vector<vector<int>> v2 = v;
		for (int i = x; i < n; i++) { //아래
			if (v2[i][y] == 0) v2[i][y] = -1;
			else if (v2[i][y] == 6) break;
		}
		for (int j = y; j < m; j++) { //오
			if (v2[x][j] == 0) v2[x][j] = -1;
			else if (v2[x][j] == 6) break;
		}
		for (int i = x; i >= 0; i--) { //위
			if (v2[i][y] == 0) v2[i][y] = -1;
			else if (v2[i][y] == 6) break;
		}
		dfs(v2, q);

		vector<vector<int>> v3 = v;
		for (int j = y; j >= 0; j--) { //왼
			if (v3[x][j] == 0)v3[x][j] = -1;
			else if (v3[x][j] == 6) break;
		}
		for (int i = x; i < n; i++) { //아래
			if (v3[i][y] == 0) v3[i][y] = -1;
			else if (v3[i][y] == 6) break;
		}
		for (int j = y; j < m; j++) { //오
			if (v3[x][j] == 0) v3[x][j] = -1;
			else if (v3[x][j] == 6) break;
		}
		dfs(v3, q);

		vector<vector<int>> v4 = v;
		for (int j = y; j < m; j++) { //오
			if (v4[x][j] == 0) v4[x][j] = -1;
			else if (v4[x][j] == 6) break;
		}
		for (int i = x; i >= 0; i--) { //위
			if (v4[i][y] == 0) v4[i][y] = -1;
			else if (v4[i][y] == 6) break;
		}
		for (int j = y; j >= 0; j--) { //왼
			if (v4[x][j] == 0)v4[x][j] = -1;
			else if (v4[x][j] == 6) break;
		}
		dfs(v4, q);

	}
	else if (v[x][y] == 5) {
		vector<vector<int>> v1 = v;
		for (int i = x; i >= 0; i--) { //위
			if (v1[i][y] == 0) v1[i][y] = -1;
			else if (v1[i][y] == 6) break;
		}
		for (int j = y; j >= 0; j--) { //왼
			if (v1[x][j] == 0)v1[x][j] = -1;
			else if (v1[x][j] == 6) break;
		}
		for (int i = x; i < n; i++) { //아래
			if (v1[i][y] == 0) v1[i][y] = -1;
			else if (v1[i][y] == 6) break;
		}
		for (int j = y; j < m; j++) { //오
			if (v1[x][j] == 0) v1[x][j] = -1;
			else if (v1[x][j] == 6) break;
		}
		dfs(v1, q);
	}
	
}
int main() {
	cin >> n >> m;
	vector<vector<int>> v;
	v.resize(n, vector<int>(m));
	int size = 0;
	queue <pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 0) size++;
			else if ( v[i][j]!=6) q.push({i,j});
		}
	}
	
	dfs(v,q);
	
	cout << size-result;
}

	