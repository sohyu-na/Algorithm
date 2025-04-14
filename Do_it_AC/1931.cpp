#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int N;
vector<pair<int, int>> v;

int main() {
	cin >> N ;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end());
	int last = 0;
	int ans = 0;
	for (int j = 0; j < N; j++) {
		if (last <= v[j].second) {
			last = v[j].first;
			ans++;
		}
	}
	cout << ans;
}