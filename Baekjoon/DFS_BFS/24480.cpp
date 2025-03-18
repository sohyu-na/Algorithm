#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
vector<vector<int>> v;
vector<bool> visited;
vector<int> res;

int ord = 0;

void dfs(int R);

int main() {

	int N, M, R;
	cin >> N >> M >> R;
	v.resize(N+1);
	visited.resize(N + 1);
	res.resize(N + 1,0);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(),greater<>());
	}
	dfs(R);
	for (int i = 1; i <= N; i++) {
		cout << res[i]<<"\n";
	}
}

void dfs(int R) {
	visited[R] = true;
	ord++;
	res[R] = ord;
	for (int x : v[R]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}