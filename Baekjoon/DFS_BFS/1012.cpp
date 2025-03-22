#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int T; cin >> T;
	int M, N, K;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		
		vector <int> vv(N,0);
		vector<vector <int>> v(M,vv);
		queue <pair<int, int>> q;

		int a, b;
		for (int j = 0; j < K; j++) {
			cin >> a >> b;
			v[a][b] = 1;
		}
		int ans = 0;
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (v[x][y]) {
					v[x][y] = 0; 
					q.push(make_pair(x, y)); 
					while (!q.empty()) {
						a = q.front().first;
						b = q.front().second; 
						q.pop();
						if (a!=M-1 and v[a+1][b]) {
							v[a + 1][b] = 0; 
							q.push(make_pair(a + 1, b));
						}
						if (b!=N-1 and v[a][b+1]) {
							v[a][b + 1] = 0; 
							q.push(make_pair(a, b+1));
						}
						if (a!=0 and v[a-1][b]) {
							v[a - 1][b] = 0;
							q.push(make_pair(a-1, b));
						}
						if (b!=0 and v[a][b-1]) {
							v[a][b - 1] = 0; 
							q.push(make_pair(a, b-1));
						}
					}
					ans++;
				}
			}
		}
		cout << ans<<"\n";
	}
}