#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[1001];
int di[1001] = {0};
int dd[1001] = {0};

void incre(int n) {	
	for (int i = 2; i <= n; i++) {
		int k = 1;
		while (i - k > 0) {
			if (arr[i - k] < arr[i]) {
				di[i] = max(di[i],di[i - k] + 1);
			}
			k++;
		}
	}
}
void decre(int n) {
	for (int i = n-1; i >=1; i--) {
		int k = 1;
		while (i + k <= n) {
			if (arr[i + k] < arr[i]) {
				dd[i] = max(dd[i], dd[i + k] + 1);
			}
			k++;
		}
	}
}
int calc(int n) {
	int maxSum = di[1] + dd[1];
	for (int i = 2; i <= n; i++) {
		maxSum = max(di[i] + dd[i], maxSum);
	}

	return maxSum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		// 입력
		cin >> arr[i];
	}
	// 계산
	incre(n);
	decre(n);

	// 출력
	cout << calc(n)+1;
}