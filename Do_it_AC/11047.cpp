#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K; cin >> N >> K;

	vector <int> v;
	v.push_back(1);
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input <= K) {
			v.push_back(input);
		}
		else {
			break;
		}
	}
	int ans = 0;
	for (auto iter = v.end()-1; iter != v.begin(); iter--) {
		int k = *iter;
		if (K >= k) {
			ans += K / k;
			K = K % k;
		}
	}
	cout << ans;

}