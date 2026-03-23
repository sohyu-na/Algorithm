#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m, h;

bool equalLine(bool v[11][31]) {
	bool result = true;
	for (int i = 1; i <= n; i++) {
		int now = i;
		for (int j = 1; j <= h; j++) {
			if (v[now][j] == true) {
				now += 1;
			}
			else if (now - 1 >= 1 and v[now - 1][j] == true) {
				//cout << now<<"//";
				now -= 1;
			}
		}
		//cout << now << " ";
		if (i != now) {
			result = false;
			break;
		}
	}
	return result;
}
int main() {
	cin >> n >> m >> h;

	int a, b;
	bool v[11][31] = { false };
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[b][a] = true;
	}//b-a 

	if (equalLine(v)) {
		cout << "0";
		return 0;
	}
	queue<pair<int, int>> q;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= h; j++) {
			if (v[i][j] == false) {
				if ((i == 1 or (i!=1 and v[i - 1][j] == false)) 
					and (i==n or (i!=n and v[i+1][j]==false))) {
					v[i][j] = true; q.push({ i,j });
					if (equalLine(v)) {
						cout << "1";
						return 0;
					}
					v[i][j] = false;
				}
			}
		}
	}
	queue<pair<int, int>> q3=q;
	while (!q.empty()) {
		int f = q.front().first;
		int s = q.front().second;
		v[f][s] = true; q.pop();
		queue<pair<int, int>> q2 = q;
		while (!q2.empty()) {
			int i = q2.front().first;
			int j = q2.front().second; q2.pop();
			if ((i == 1 or (i != 1 and v[i - 1][j] == false))
				and (i == n or (i != n and v[i + 1][j] == false))) {
				v[i][j] = true; 
				if (equalLine(v)) {
					cout << "2";
					return 0;
				}
				v[i][j] = false;
			}
		}
		v[f][s] = false;
	}

	while (!q3.empty()) {
		int f = q3.front().first;
		int s = q3.front().second;
		v[f][s] = true; q3.pop();
		queue<pair<int, int>> q2 = q3;
		while (!q2.empty()) {
			int i = q2.front().first;
			int j = q2.front().second; q2.pop();
			if ((i == 1 or (i != 1 and v[i - 1][j] == false))
				and (i == n or (i != n and v[i + 1][j] == false))) {
				v[i][j] = true;
				queue<pair<int, int>> q4 = q2;
				while (!q4.empty()) {
					int x = q4.front().first;
					int y = q4.front().second; q4.pop();
					if ((x == 1 or (x != 1 and v[x - 1][y] == false))
						and (x == n or (x != n and v[x + 1][y] == false))) {
						v[x][y] = true; 
						if (equalLine(v)) {
							cout << "3";
							return 0;
						}
						v[x][y] = false;
					}
				}
				v[i][j] = false;
			}
		}
		v[f][s] = false;
	}

	cout << "-1";
	return 0;
}