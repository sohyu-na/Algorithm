#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std; 


int main() {
	int n, m; cin >> n >> m;
	int a, b;
	vector<vector<int>> v(n + 1);
	vector<int> indgree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		indgree[b]++;
	}
	set<int> s;
	for (int i = 1; i <= n; i++) {
		if (indgree[i] == 0) s.insert(i);
	}

	while (!s.empty()) {
		int f = *s.begin();
		s.erase(f);
		cout << f << " ";
		
		for (int i = 0; i < v[f].size(); i++) {
			int next = v[f][i];
			indgree[next]--;
			if (indgree[next] == 0) s.insert(next);
		}
	}


	return 0;
}

	