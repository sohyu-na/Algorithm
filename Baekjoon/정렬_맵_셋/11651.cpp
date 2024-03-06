#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else
		return a.first < b.first;
}
int main() {

	int n;  cin >> n;
	vector <pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v[i] = make_pair(x, y);
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}