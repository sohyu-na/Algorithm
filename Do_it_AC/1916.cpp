#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1);
	vector<bool> visited(n + 1,false);
	int s, e, c;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		v[s].push_back(make_pair(e, c));
	}
	vector<int> res(n + 1,INT_MAX);
	int a, b; cin >> a >> b;
	res[a] = 0;

	int mnode;
	while (true) {
		for (int i = 1; i < n + 1; i++) {
			if (visited[i] == false) {
				mnode = i; break;
			}
			else {
				if (i == n) {
					cout << res[b];
					return 0;
				}
			}
		}
		for (int i = mnode + 1; i < n + 1; i++) {
			if (res[mnode] > res[i] and visited[i] == false) {
				mnode = i;
			}
		}
		// 방문배열 업데이트
		visited[mnode] = true;

		for (int i = 0; i < v[mnode].size(); i++) {
			int nn = v[mnode][i].first;
			int nc = v[mnode][i].second;
			if (res[mnode] != INT_MAX) {
				res[nn] = min(res[nn], res[mnode] + nc);
			}
		}
	}
}
