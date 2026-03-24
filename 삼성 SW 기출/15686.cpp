#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std; 
int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> ch;

bool choice[14] = { false };
int result = INT_MAX;
void calcDistance() {
	int totalminch = 0;
	for (int i = 0; i < house.size(); i++) {
		int minch = INT_MAX;
		int xi = house[i].first;
		int yi = house[i].second;
		for (int j = 0; j < ch.size(); j++) {
			if (choice[j]) {
				int xj = ch[j].first;
				int yj = ch[j].second;
				minch = min(minch, abs(xi - xj) + abs(yi - yj));
			}
		}
		totalminch += minch;
	}
	result = min(result, totalminch);
}
void dfs(int s,int cnt) {
	if (cnt == m) {
		calcDistance();
		return;
	}
	for (int i = s; i < ch.size(); i++) {
		choice[i] = true; 
		dfs(i + 1, cnt + 1);
		choice[i] = false;
	}
	return;

}
int main() {
	cin >> n>>m;
	int k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> k;
			if (k == 1) {
				house.push_back({ i,j });
			}
			else if (k == 2) {
				ch.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);

	cout << result;
}

	