#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	long long n; cin >> n;
	long long result = n;

	for (long long i = 2; i <= sqrt(n);i++) {
		//소수일때 
		if (n % i == 0) {
		result = result - result / i;
			while (n % i == 0) {
				n = n / i;
			}
		}
	}
	if (n > 1) {
		result = result - result / n;
	}
	cout << result;
}