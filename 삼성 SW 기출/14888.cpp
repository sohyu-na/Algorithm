#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;
int number[12];

long long minV = 10e9;
long long maxV = -10e9;

void calc(int i,int p, int m, int x, int d, long long v) {
	if (i == n) {
		minV = min(minV, v);
		maxV = max(maxV, v);
		return;
	}
	long long res;
	if (p > 0) {
		res = v + number[i];
		calc(i + 1, p - 1, m, x, d,res);
	}
	if (m > 0) {
		res = v - number[i];
		calc(i + 1, p, m-1, x, d, res);
	}
	if (x > 0) {
		res = v * number[i];
		calc(i + 1, p, m, x-1, d, res);
	}
	if (d > 0) {
		res = v / number[i];	
		calc(i + 1, p , m, x, d-1, res);
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	int p, m, x, d;
	cin >> p >> m >> x >> d;
	

	calc(1, p, m, x, d, number[0]);
	cout << maxV << "\n" << minV;
		
}

	