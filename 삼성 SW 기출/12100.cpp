#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;
int maxi = 0;

vector<int> moveLine(vector<int> line) {
	vector<int> temp;
	for (int x : line) {
		if (x != 0) temp.push_back(x);
	}

	vector<int> merged;
	for (int i = 0; i < temp.size(); i++) {
		if (i + 1 < temp.size() and temp[i] == temp[i + 1]) {
			merged.push_back(temp[i] * 2);
			i++;
		}
		else {
			merged.push_back(temp[i]);
		}
	}

	while (merged.size() < n) merged.push_back(0);

	return merged;
}
vector<vector<int>> move(vector<vector<int>> v, int dir) {
	if (dir == 0) {
		for (int i = 0; i < n; i++) {
			v[i]=moveLine(v[i]);
		}
		return v;
	}
	else if (dir == 1) {
		for (int i = 0; i < n; i++) {
			vector<int> temp;
			for (int j = n - 1; j >= 0; j--) {
				temp.push_back(v[i][j]);
			}
			temp = moveLine(temp);
			
			vector<int> back;
			for (int j = n - 1; j >= 0; j--) {
				back.push_back(temp[j]);
			}
			v[i] = back;
		}
		return v;
	}
	else if (dir == 2) {
		for (int j = 0; j < n; j++) {
			vector<int> temp;
			for (int i = 0; i < n; i++) {
				temp.push_back(v[i][j]);
			}
			temp = moveLine(temp);

			for (int i = 0; i < n; i++) {
				v[i][j] = temp[i];
			}
		}
		return v;
	}
	else {
		for (int j = 0; j < n; j++) {
			vector<int> temp;
			for (int i = n - 1; i >= 0; i--) {
				temp.push_back(v[i][j]);
			}
			temp = moveLine(temp);

			vector<int> back;
			for (int i = n - 1; i >= 0; i--) {
				back.push_back(temp[i]);
			}
			for (int i = 0; i < n; i++) {
				v[i][j] = back[i];
			}
		}
		return v;
	}
}

void dfs(vector<vector<int>> v, int dep) {
	if (dep == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maxi < v[i][j]) {
					maxi = v[i][j];
				}
			}
		}
		return;
	}
	
	for (int dir = 0; dir < 4; dir++) {
		dfs(move(v, dir), dep + 1);
	}
	return;
}

int main() {
	cin >> n;

	vector<vector<int>> v(n);
	int k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> k;
			v[i].push_back(k);
		}
	}
	dfs(v, 0);

	cout << maxi;

}