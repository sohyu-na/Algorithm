#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
	int M, N; cin >> M >> N;
	if (M == 1 and N!=1) {
		M++;
	}
	if (M == 2) {
		cout << M << "\n";
		M++;
	}
	if (M % 2 == 0) {
		M += 1;
	}
	//시작점 - 홀수 
	for (int i = M; i <= N; i += 2) { //짝수는 검사안함
		bool c = false;
		for (int j = 3; j <= sqrt(i); j++) {//나눠보는건 i 이하의 소수로만 나눠보면 될 듯 
			if (i % j == 0) {
				c = true;//소수가 아님
				break;
			}
		}
		if (!c) {
			cout << i << "\n";
		}
	}

}