#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
vector<int> vv;
vector <vector<int>> v;
queue <pair<int, int>> q;

int a[] = { -1,0,1,0 };
int b[] = { 0,1,0,-1 };

int main() {
	cin >> M >> N;
	vv.resize(M);
	v.resize(N,vv);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j]==1) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int f = q.front().first;
		int s = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			if (f + a[i] >= 0 and f + a[i] < N and s + b[i] >= 0 and s + b[i] < M) {
				if (v[f + a[i]][s + b[i]] == 0) {
					v[f + a[i]][s + b[i]] = v[f][s] + 1;
					q.push(make_pair(f + a[i], s + b[i]));
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			if (ans < v[i][j]) {
				ans = v[i][j];
			}
		}
	}
	cout << ans-1;
	return 0;
}