#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	long long min, max; cin >> min >> max;
	vector<bool> check(max - min + 1);

	for (long long i = 2; i * i <= max; i++) {
		
		long long t = min / (i * i);
		if (min % (i * i)!=0) {
			t++;cout << i;
		}
		for (long long j = t; (i * i) * j <= max; j++) {
			check[(int)((j * (i * i)) - min)] = true;
		}
	}
	int cnt = 0;
	for (int i = 0; i < check.size(); i++) {
		if (!check[i]) {
			cnt++;
		}
	}
	cout << cnt;
}