#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
		return a.first < b.first;
}

int main() {

	int n;  cin >> n;
	vector <pair<int, string>> v(n);

	for (int i = 0; i < n; i++) {
		int x; string str; cin >> x >> str;
		v[i] = make_pair(x, str);
	}
	stable_sort(v.begin(), v.end(), cmp); //순서유지를 위해 

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}