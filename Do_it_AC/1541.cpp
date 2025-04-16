#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	string arr;
	cin >> arr;
	int sum = 0;
	int n = 0;
	bool check = false;
	for (int i = 0; i < arr.length(); i++) {
		if (arr[i] == '-') {
			if (check) {
				sum -= n;
				n = 0;
			}
			else {
				sum += n;
				n = 0;
			}
			check = true;
		}
		else if (arr[i] == '+') {
			if (check) {
				sum -= n;
				n = 0;
			}
			else {
				sum += n;
				n = 0;
			}
		}
		else {
			n *= 10;
			n += arr[i] - '0';
		}
	}
	if (check) {
		sum -= n;
	}
	else {
		sum += n;
	}
	cout << sum;
}