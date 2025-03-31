#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N,H;
struct Point{ int a; int b; int c; };
vector<int> vvv;
vector <vector<int>> vv;
vector<vector<vector<int>>> v;
queue < Point> q;

int a[] = { -1,0,1,0 ,0,0};
int b[] = { 0,1,0,-1,0,0 };
int c[] = { 0,0,0,0,1,-1 };

int main() {
	cin >> M >> N>>H;
	vvv.resize(M);
	vv.resize(N,vvv);
	v.resize(H, vv);

	for (int u = 0; u < H; u++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> v[u][i][j];
				if (v[u][i][j] == 1) {
					Point p;
					p.a = u;
					p.b = i;
					p.c = j;
					q.push(p);
				}
			}
		}
	}

	while (!q.empty()) {
		int t = q.front().a;
		int f = q.front().b;
		int s = q.front().c;

		q.pop();
		for (int i = 0; i < 6; i++) {
			if (t + c[i] >= 0 and t + c[i] < H and f + a[i] >= 0 and f + a[i] < N and s + b[i] >= 0 and s + b[i] < M) {
				if (v[t+c[i]][f + a[i]][s + b[i]] == 0) {
					v[t + c[i]][f + a[i]][s + b[i]] = v[t][f][s] + 1;
					Point p;
					p.a = t + c[i];
					p.b = f + a[i];
					p.c = s + b[i];
					q.push(p);
				}
			}
		}
	}

	int ans = 0;
	for (int u = 0; u < H; u++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v[u][i][j] == 0) {
					cout << "-1";
					return 0;
				}
				if (ans < v[u][i][j]) {
					ans = v[u][i][j];
				}
			}
		}
	}
	cout << ans-1;
	return 0;
}