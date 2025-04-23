#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N; cin >> N;
	
	for (int i = N ;; i++) {
		bool c = true;
		if (i == 1) {
			c = false;
		}
		for (int j = 2; j <= (int) sqrt(i); j++) {
			if (i % j == 0) {
				c = false;
				break;
			}
		}
		if(c){//소수이면
			int temp = i;
			vector<int> t;
			while (temp>0) {
				t.push_back(temp % 10);
				temp /= 10;
			}
			int sum = 0; temp = 1;
			while (!t.empty()) {
				sum += temp*t.back();
				t.pop_back();
				temp *= 10;
			}
			if (i == sum) {
				cout << i;
				break;
			}
		}

	}
	return 0;
}