#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<int> cnt;
vector<vector<int>> v;

int main() {
	int n, m; cin >> n >> m;
	v.resize(n + 1);
	cnt.resize(n + 1,0);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);//a가 b를 신뢰함 
	}
	for (int i = 1; i < n + 1; i++) { //각 노드에 대해서 bfs 각각 수행 
		vector<bool> check(n + 1, false);
		queue <int> q;
		q.push(i); check[i] = true;
		
		while (!q.empty()) {
			int c = q.front(); q.pop();
			for (int j : v[c]) {
				if (!check[j]) {
					check[j] = true;
					cnt[j]++;
					q.push(j);
				}
			}
		}
	}
	int max = 0;
	for (int i = 1; i < n + 1; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
		}
	}
	for (int i = 1; i < n + 1; i++) {
		if (max == cnt[i]) {
			cout<<i<<" ";
		}
	}
}