#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> v(4, vector<int>(8));
int turn[4] = { 0 };

void rotateCounterClockwise(int j) {// 반시계
	int temp = v[j][0];
	for (int i = 1; i < 8; i++) {
		v[j][i - 1] = v[j][i];
	}
	v[j][7] = temp;
	return;
}
void rotateClockwise(int j) {//1=0 2=1 7=6 
	int temp = v[j][7];
	for (int i = 7; i >0 ; i--) {
		v[j][i] = v[j][i - 1];
	}
	v[j][0] = temp;
	return;
}

void checkNext(int n,int dir) {
	if (n<3 and turn[n+1]==0 and v[n][2] != v[n + 1][6]) {
		turn[n + 1] = -dir;
		checkNext(n + 1,-dir);
	}
	if (n > 0 and turn[n-1]==0 and v[n - 1][2] != v[n][6]) {
		turn[n - 1] = -dir;
		checkNext(n - 1,-dir);
	}
	return;
}
int main() {
	string str;
	for (int i = 0; i < 4; i++) {
		cin >> str;
		for (int j = 0; j < 8; j++) {
			v[i][j] = str[j]-'0';
		}
	}
	int k; cin >> k;
	int n, dir;
	for (int i = 0; i < k; i++) {
		cin >> n >> dir;
		n--;
		turn[n] = dir;

		checkNext(n,dir);
		for (int j = 0; j < 4; j++) {
			if (turn[j] == -1) {// 반시계
				rotateCounterClockwise(j);
			}
			else if (turn[j] == 1) {// 시계
				rotateClockwise(j);
			}
			turn[j] = 0;
		}
	}
	int score = 0;
	int two = 1;
	for (int i = 0; i < 4; i++) {
		if (v[i][0] == 1) {
			score += two;
		}
		two *= 2;
	}
	cout << score;
}

	