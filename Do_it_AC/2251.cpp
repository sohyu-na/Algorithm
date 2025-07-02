#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
set<int> s;
int visited[201][201];
int a, b, c; 

void dfs(int x, int y, int z) {
	visited[x][y] = true;
	if (x == 0) {
		s.insert(z);
	}

	//a b
	if (x + y <= b) {
		if (!visited[0][x + y]) {
			dfs(0, x + y, z);
		}
	}
	else {
		if (!visited[x + y - b][b]) {
			dfs(x + y - b, b, z);
		}
	}
	//a c
	if (x + z <= c) {
		if (!visited[0][y]) {
			dfs(0, y, x+z);
		}
	}
	else {
		if (!visited[x + y - c][y]) {
			dfs(x + z - c, y, c);
		}
	}
	//b a
	if (x + y <= a) {
		if (!visited[x+y][0]) {
			dfs(x+y, 0, z);
		}
	}
	else {
		if (!visited[a][x + y - a]) {
			dfs(a, x+y-a, z);
		}
	}
	//b c
	if (y + z <= c) {
		if (!visited[x][0]) {
			dfs(x, 0, y + z);
		}
	}
	else {
		if (!visited[x][y + z - c]) {
			dfs(x, y + z-c, c);
		}
	}
	//c a
	if (x + z <= a) {
		if (!visited[x + z][y]) {
			dfs(x+z, y, 0);
		}
	}
	else {
		if (!visited[a][y]) {
			dfs(a, y , x + z-a);
		}
	}
	//c b
	if (y + z <= b) {
		if (!visited[x][y + z]) {
			dfs(x, y+z, 0);
		}
	}
	else {
		if (!visited[x][y]) {
			dfs(x, b, y + z - b);
		}
	}
}
int main() {
	cin >> a >> b >> c;
	
	dfs(0, 0, c);

	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter<<" ";
	}
}