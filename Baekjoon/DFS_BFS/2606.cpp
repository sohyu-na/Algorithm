#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector<int>> v;
vector <bool> visited;
queue<int> q;

int ans = 0;

void bfs(int a);

int main() {
	int N; cin >> N;
	int M; cin >> M;

	v.resize(N+1);
	visited.resize(N + 1);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);

	cout << ans;
}

void bfs(int a) {
	visited[a] = true; 
	q.push(a);
	
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int x : v[f]) {
			if (!visited[x]) {
				visited[x] = true; ans++;
				q.push(x);
			}
		}


	}

}