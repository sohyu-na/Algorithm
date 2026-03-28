#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std; 

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> a(n + 1, vector<int>(n + 1));
	vector<vector<int>> ing(n + 1, vector<int>(n + 1,5));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	int x, y, z;
	deque<int> v[11][11];
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		v[x][y].push_back(z);
	}
	while (k--) {
		queue<pair<int, int>> q;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// spring
				deque<int> survive;
				int die = 0;
				while(!v[i][j].empty()){
					int age = v[i][j].front();
					if (age <= ing[i][j]) {
						ing[i][j] -= age;
						survive.push_back(age + 1);
					}
					else {
						die += age / 2;
					}
					v[i][j].pop_front();
				}
				v[i][j] = survive;

				//summer
				ing[i][j] += die;

				//fall
				for (auto age : v[i][j]){
					if (age % 5 == 0) {
						if (i - 1 >= 1 and j - 1 >= 1) {
							q.push({ i - 1,j - 1 });
						}
						if (i - 1 >= 1) {
							q.push({ i - 1,j });
						}
						if (i - 1 >= 1 and j + 1 <= n) {
							q.push({ i - 1,j + 1 });
						}
						if (j - 1 >= 1) {
							q.push({ i,j - 1 });
						}
						if (j + 1 <= n) {
							q.push({ i,j + 1 });
						}
						if (i + 1 <= n and j - 1 >= 1) {
							q.push({ i + 1,j - 1 });
						}
						if (i + 1 <= n) {
							q.push({ i + 1,j});
						}
						if (i + 1 <= n and j + 1 <= n) {
							q.push({ i + 1,j + 1 });
						}
					}
				}
				//winter
				ing[i][j] += a[i][j];
			}
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			v[x][y].push_front(1);
			q.pop();
		}
	} 
	int surviveTree = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!v[i][j].empty()) {
				surviveTree += v[i][j].size();
			}
		}
	}
	cout << surviveTree;
}

	