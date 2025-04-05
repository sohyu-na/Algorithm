#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N, M;

vector<int> vv;
vector<vector<int>> v;

vector<vector<bool>> visited;
queue<pair<int, int>> q;

void bfs(int a, int b);


int main() {
	 cin >> N >> M;
	vv.resize(M);
	v.resize(N, vv);

	visited.resize(N);

	string arr;
	for (int i = 0; i < N; i++) {
		cin >> arr;
		for (int j = 0; j < arr.size(); j++) {
			v[i][j] = arr[j] - '0';
			visited[i].push_back(false);
		}
	}

	bfs(0, 0); 
	cout << v[N - 1][M - 1];

}

void bfs(int a, int b) {
	q.push(make_pair(a, b));
	visited[a][b] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a != 0 and v[a - 1][b] and !visited[a-1][b]) {
			q.push(make_pair(a-1, b));
			visited[a-1][b] = true;
			v[a - 1][b] = v[a][b] + 1;
		}
		if (b != 0 and v[a][b - 1] and !visited[a][b-1]) {
			q.push(make_pair(a , b-1));
			visited[a][b-1] = true;
			v[a][b-1] = v[a][b] + 1;
		}
		if (a != N - 1 and v[a + 1][b] and !visited[a +1][b]) {
			q.push(make_pair(a + 1, b));
			visited[a + 1][b] = true;
			v[a + 1][b] = v[a][b] + 1;
		}
		if (b != M - 1 and v[a][b + 1] and !visited[a][b + 1]) {
			q.push(make_pair(a, b + 1));
			visited[a][b + 1] = true;
			v[a][b + 1] = v[a][b] + 1;
		}
	}
}