#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int cntFib = 0;
int cntFibonacci = 0;
int f[40] = { 0 };

int fib(int k) {
	if (k == 1 or k == 2) {
		cntFib++;
		return 1;
	}
	else {
		return fib(k - 1) + fib(k - 2);
	}
}
int fibonacci(int k) {
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= k; i++) {
		f[i] = f[i - 1] + f[i - 2];
		cntFibonacci++;
	}
	return f[k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int k; cin >> k;
	
	// 계산 
	fib(k);
	fibonacci(k);

	// 출력 
	cout << cntFib << " " << cntFibonacci;
}