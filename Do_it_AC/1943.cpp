#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int T; cin >> T;
	int a, b;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		int min = a;
		int ans = a * b;
		bool c[45001];
		memset(c, true, 45001);
		for (int i = 2; i <= min; i++) {
			if (c[i]) {
				
				while (a % i == 0 and b % i == 0) {
					a /= i;
					b /= i;
					ans /= i;
				}//cout << i <<"/" << ans<<"\n";
				for (int j = 2; j * i < min; j++) {
					c[j * i] = false;
				}
			}
		}
		cout << ans << "\n";
	}
}