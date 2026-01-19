#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

vector<vector<int>>v(9);

bool solved = false;
bool check(int i, int j) {
	if (v[i][j] == 0) {
		bool arr[10] = { false };
		for (int k = 0; k < 9; k++) {
			if (v[i][k] != 0) {
				arr[v[i][k]] = true;
			}
			if (v[k][j] != 0) {
				arr[v[k][j]] = true;
			}
		}
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				if (v[3*(i / 3) + a][3 * (j / 3) + b] != 0) {
					arr[v[3 * (i / 3) + a][3 * (j / 3) + b]] = true;
				}
			}
		}
		for (int k = 1; k < 10; k++) {
            v[i][j] = k;
            if (i == 8 and j == 8) {
                solved = true;
                return true;
            }

            bool ok;
            if (j == 8) {
                ok = check(i + 1, 0);
            }
            else {
                ok = check(i, j + 1);
            }
            
            if (ok) {
                return true;
            }
            else {
                v[i][j] = 0; 
            }
		}
		return false;
	}
	else {
		if (i == 8 and j == 8) {
			solved = true;
			return true;
		}
		else if (j == 8) {
			return check(i + 1, 0);
		}
		else {
			return check(i, j + 1);
		}
	}
		
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int k;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> k;
			v[i].push_back(k);
		}
	}
	// 계산 -> 재귀
	check(0, 0);

	// 출력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}