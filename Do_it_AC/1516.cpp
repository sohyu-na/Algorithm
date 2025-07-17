#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int arr[501];
int cnt[501];
int res[501];

int main() {
	cin >> n ;
	vector<vector<int>> v(n+1);
	int x;
	for (int i = 1; i < n+1; i++) {
		cin >> arr[i]; //걸리는 시간 
		cin >> x;
		while (x != -1) {
			v[x].push_back(i);
			cnt[i]++;
			cin >> x;
		}
	}
	queue <int> q;

	for (int i = 1; i < n+1; i++) {
		if (cnt[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int i : v[f]) {
			cnt[i]--; 
			res[i] = max(res[i], res[f] + arr[f]);
			if (cnt[i] == 0) {
				q.push(i);
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		cout << res[i]+arr[i] << "\n";
	}
}
