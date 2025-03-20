#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<vector<int>> v;
vector<int> res;
vector<bool> visited;
queue <int> q;
int ord = 0;

void bfs(int R);

int main() {

	int N, M, R;
	cin >> N >> M >> R;
	v.resize(N+1);
	visited.resize(N + 1, false);
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
	bfs(R);
	for (int i = 1; i <= N; i++) {
		cout << res[i]<<"\n";
	}
}

void bfs(int R) {
	q.push(R);
	visited[R] = true;
	while (!q.empty()) {
		int f = q.front();
		ord++;
		res[f] = ord;

		q.pop();
		for (int x : v[f]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
	return;
}