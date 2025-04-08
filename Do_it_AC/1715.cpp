#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int N; cin >> N ;

	multiset <long long> s;
	int k;
	for (int i = 0; i < N; i++) {
		cin >> k;
		s.insert(k);
	}
	long long ans = 0;
	while (s.size() > 1) {
		long long a = *s.begin();
		s.erase(s.begin());
		long long b = *s.begin();
		s.erase(s.begin());
		ans += (a + b);

		s.insert(a + b);

	}
	cout << ans;

}