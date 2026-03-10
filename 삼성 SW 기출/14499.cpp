#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;

	vector<vector<int>> v(n ,vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
				//밑,위,동,서,남,북
	int dice[6] = { 0,0,0,0,0,0 };
	
	int xd[5] = { 0,0,0,- 1,1 };
	int yd[5] = { 0,1,-1,0,0 };

	
	for (int i = 0; i < k; i++) {
		int a; cin >> a; 
		if (x + xd[a] >= 0 and x + xd[a] < n and y + yd[a] >= 0 and y + yd[a] < m) {
			x += xd[a];
			y += yd[a];
			int newdice[6] = { 0,0,0,0,0,0 };
			if (a == 1) {
				newdice[0] = dice[2];
				newdice[1] = dice[3];
				newdice[2] = dice[1];
				newdice[3] = dice[0];
				newdice[4] = dice[4];
				newdice[5] = dice[5];
			}
			else if (a == 2) {
				newdice[0] = dice[3];
				newdice[1] = dice[2];
				newdice[2] = dice[0];
				newdice[3] = dice[1];
				newdice[4] = dice[4];
				newdice[5] = dice[5];
			}
			else if (a == 3) {
				newdice[0] = dice[4];
				newdice[1] = dice[5];
				newdice[2] = dice[2];
				newdice[3] = dice[3];
				newdice[4] = dice[1];
				newdice[5] = dice[0];
			}
			else if(a==4){
				newdice[0] = dice[5];
				newdice[1] = dice[4];
				newdice[2] = dice[2];
				newdice[3] = dice[3];
				newdice[4] = dice[0];
				newdice[5] = dice[1];
			}
			if (v[x][y] != 0) {
				newdice[0] = v[x][y]; v[x][y] = 0;
			}
			else {
				v[x][y] = newdice[0];
			}
            for (int j = 0; j < 6; j++) dice[j] = newdice[j];

			cout << dice[1] << "\n";
		}
	}

}