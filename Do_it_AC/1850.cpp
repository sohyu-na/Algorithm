#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	long long a, b; cin >> a >> b;
	if (a > b) {
		swap(a, b);
	}
	//a와 b의 최대공약수만큼 출력하면됨 
	//최대공약수 구하기 
	int key = __gcd(a, b);

	//출력
	for (int i = 0; i < key; i++) {
		cout << "1";
	}

}