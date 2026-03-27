#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std; 

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int main() {
	int n, l, r; cin >> n >> l >> r;
	vector<vector<int>> v(n);
	int k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> k;
			v[i].push_back(k);
		}
	}
	queue<pair<int, int>> q;
	
	int cnt = 0;
	while (true) {
		bool check[51][51] = { false };
		bool openLine = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					q.push({ i,j }); check[i][j] = true;
					queue<pair<int, int>> div;
					div.push({ i,j }); int divSum = v[i][j];
					while (!q.empty()) {
						int x = q.front().first; 
						int y = q.front().second; 
						q.pop();
						for (int dir = 0; dir < 4; dir++) {
							if (x + xd[dir] >= 0 and x + xd[dir] < n and y + yd[dir] >= 0 and y + yd[dir] < n) {
								if (!check[x + xd[dir]][y + yd[dir]] and abs(v[x][y] - v[x + xd[dir]][y + yd[dir]]) >= l and abs(v[x][y] - v[x + xd[dir]][y + yd[dir]]) <= r) {
									openLine = true;
									q.push({ x + xd[dir],y + yd[dir] }); check[x + xd[dir]][y + yd[dir]] = true;
									div.push({ x + xd[dir],y + yd[dir] }); divSum += v[x + xd[dir]][y + yd[dir]];
								}
							}
						}
					}

					if (openLine) {
						divSum = divSum / (int)div.size();
						
						while (!div.empty()) {
							int x = div.front().first;
							int y = div.front().second;
							v[x][y] = divSum;
							div.pop();
						}
					}
				}
			}
		}
		if (!openLine) {
			break;
		}
		else {
			cnt++;
		}
	}
	cout << cnt;

}

	