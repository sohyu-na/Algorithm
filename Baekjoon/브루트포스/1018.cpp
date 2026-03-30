#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std; 
vector<vector<char>> v;
int checkBoard(char target,int a, int b) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (v[a + i][b + j] != target) cnt++;
			target = (target == 'W') ? 'B' : 'W';
		}
		target = (target == 'W') ? 'B' : 'W';
	}
	return cnt;
}
int main() {
	int n, m; cin >> n >> m;
	string str;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			v[i].push_back(str[j]);
		}
	}
	int minV = INT_MAX;
	for (int i = 0; i < n-7; i++) {
		for (int j = 0; j < m-7; j++) { 
			int cntB = checkBoard('B', i, j); minV = min(minV, cntB);
			int cntW= checkBoard('W', i, j); minV = min(minV, cntW); 
		}
	}
	cout << minV;
}

	