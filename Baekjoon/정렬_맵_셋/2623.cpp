#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std; 

int main() {
	int n, m; cin >> n >> m;
	int x,first,next;
	vector<vector<int>> v(n + 1);
	int indgree[1001] = { 0 };
	for (int i = 0; i < m; i++) {
		cin >> x >> first;
		for (int j = 1; j < x; j++) {
			cin >> next;
			v[first].push_back(next);
			indgree[next]++;
			first = next;
		}
	}
	queue<int> q;
	queue<int> result;
	for (int i = 1; i <= n; i++) {
		if (indgree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int f = q.front(); q.pop();
		result.push(f);

		for (auto next : v[f]) {
			indgree[next]--;
			if (indgree[next] == 0) q.push(next);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indgree[i] != 0) {
			cout << "0"; return 0;
		}
	}
	while (!result.empty()) {
		int f = result.front(); result.pop();
		if(result.empty()) cout << f;
		else cout << f << "\n";
	}
	return 0;
}

	