#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	long long A, B; cin >> A >> B;
	int cnt = 0;
	long long b = (long long)sqrt(B);
	
	//소수를 구하고 소수의 제곱을 찾기

	vector<bool> isPrime(b + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (long long i = 2; i <= b; i++) {
		if (isPrime[i]) {//소수이면
			for (long long j = i + i; j <= b; j += i) {
				isPrime[j] = false;
			}
			long long temp = i * i;
			while (temp < A) {
				temp *= i;
			}
			while (temp <= B) {
				cnt++; //cout << temp<<"/";
				if (temp <= B / i) {
					temp *= i;
				}
				else {
					break;
				}
			}
		}
	}
	cout << cnt;
}