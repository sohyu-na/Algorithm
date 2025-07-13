#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int arr[32001];

int main() {
	cin >> n >> m;
	vector<vector<int>> v(n+1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;//a->b
		v[a].push_back(b);
		arr[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int f = q.front();
		cout << f << " ";
		q.pop();

		for (int i : v[f]) {
			if (--arr[i] == 0) {
				q.push(i);
			}
		}
	}
}