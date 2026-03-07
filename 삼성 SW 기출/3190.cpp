#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n; //1~n
queue <pair<int, char>> q;
queue<pair<int, int>> snake;
vector<vector<int>> board;

//0-오 1-아래 2-왼 3-위 
int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int game(int t, int dir) {
	while (true) {
		int a = snake.back().first;
		int b = snake.back().second;

		a += xd[dir];
		b += yd[dir];

		if (a > n or a<1 or b>n or b < 1) return t+1;
		if (board[a][b] == 1) return t+1;

		if (board[a][b] == 0) {
			board[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		board[a][b] = 1; snake.push(make_pair(a, b));
		t++;

		if (!q.empty() and t == q.front().first) {
			if (q.front().second == 'L') dir = (dir + 3) % 4;
			else dir = (dir + 1) % 4;
			q.pop();
		}
	}
}
int main() {
	int k; cin >> n>>k;
	board.resize(n+1,vector<int>(n+1,0)); 

	board[1][1] = 1;//뱀
	snake.push(make_pair(1, 1));

	int a, b; 
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		board[a][b] = -1;//사과 
	}

	int l; cin >> l; 
	int x; char c;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		q.push(make_pair(x, c));
	}
	cout << game( 0, 0 );
}