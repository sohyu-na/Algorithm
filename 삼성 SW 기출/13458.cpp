#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n; cin >> n;
	int a;
	vector<int> v;
	for (int i = 0; i<n; i++) {
		cin >> a;
		v.push_back(a);
	}
	int b, c; cin >> b >> c;

	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		v[i] -= b; cnt++;
		if (v[i] <=0) {
			continue;
		}
		else {
			cnt += v[i] / c;
			if (v[i] % c > 0) {
				cnt++;
			}
		}
	}
	cout << cnt;
}