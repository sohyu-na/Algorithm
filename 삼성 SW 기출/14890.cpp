#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n,l; cin >> n>>l;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int st = v[i][0];
		int eq = 1;
		for (int j = 1; j < n; j++) {
			if (abs(v[i][j-1] - v[i][j]) > 1) break;
			if (st == v[i][j]) {
				eq++; //동일 높이 
			}
			if (st == v[i][j] + 1) { // 낮아지는 경우 
				bool check = true;
				for (int k = 1; k < l; k++) {
					if (j + k >= n or v[i][j] != v[i][j + k]) {
						check = false;
						break;
					}
				}
				if (!check) {
					break;
				}
				else {
					j = j + (l-1);
				}
				st = v[i][j];  eq = 0;
			}
			if (st + 1 == v[i][j]) { // 높아지는 경우 
				if (eq < l) { 
					break;
				}
				st = v[i][j]; eq = 1;
			}
			if (j == n - 1) {
				cnt++;
			}
		}
	}	
	for (int j = 0; j < n; j++) {
		int st = v[0][j];
		int eq = 1;
		for (int i = 1; i < n; i++) {
			if (abs(v[i-1][j] - v[i][j]) > 1) break;
			if (st == v[i][j]) {
				eq++; //동일 높이 
			}
			if (st == v[i][j] + 1) {
				bool check = true;
				for (int k = 1; k < l; k++) {
					if (i + k >= n) {
						check = false;
						break;
					}
					else {
						if (v[i][j] != v[i + k][j]) {
							check = false;
							break;
						}
					}
				}
				if (!check) {
					break;
				}
				else {
					i =i + (l-1);
				}
				st = v[i][j];  eq = 0;
			}
			if (st + 1 == v[i][j]) { // 높아지는 경우 
				if (eq < l) {
					break;
				}
				st = v[i][j]; eq = 1;
			}
			if (i == n - 1) {
				cnt++;
			}
		}			
	}
	cout << cnt;
}

	