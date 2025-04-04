#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
struct info {
	int a;
	int b;
	bool ck;
};
queue <info> q;
queue <pair<int, int>> check;

int a[] = { 0,0,1,-1 };
int b[] = { 1,-1,0,0 };
int visited[1000][1000][2]; // 방문 여부 배열

int main() {
	cin >> N >> M;
	vector<vector<int>> v(N);

	string arr;
	for (int i = 0; i < N; i++) {
		cin >> arr;
		for (int j = 0; j < M; j++) {
			v[i].push_back(arr[j]-'0');
		}	
	}

	q.push({0, 0, false});
	visited[0][0][0] = 1;//뚫지않고 0,0에서 시작

	while (!q.empty()) {
		int f = q.front().a;
		int s = q.front().b;
		bool t = q.front().ck;
		q.pop();
		//뚫고 방문 vs 뚫지 않고 방문이 다르니까 

		for (int i = 0; i < 4; i++) {
			if (f + a[i] >= 0 and f + a[i] < N and s + b[i] >= 0 and s + b[i] < M) {
				if (v[f + a[i]][s + b[i]] == 0 and visited[f + a[i]][s + b[i]][t] == 0) {//갈 수 있고 방문하지 않은 경우(뚫은 경우랑 뚫지 않은 경우랑 나눠서)
					q.push(info{ f + a[i], s + b[i],t }); //cout << f + a[i] << s + b[i] << "//\n";
					visited[f + a[i]][s + b[i]][t] = visited[f][s][t] + 1;
				}
				if (v[f + a[i]][s + b[i]] == 1 and t==false) {//갈 수 없는데 아직 벽을 뚫지 않은경우 
					q.push(info{ f + a[i], s + b[i],true }); //cout << f + a[i] << s + b[i] << "??\n";
					visited[f + a[i]][s + b[i]][true] = visited[f][s][t] + 1;
				}
			}
		}
	} 
	if (visited[N - 1][M - 1][0] == 0 and visited[N - 1][M - 1][1]==0) {
		cout << "-1";
	}
	else if (visited[N - 1][M - 1][0] == 0) {
		cout << visited[N - 1][M - 1][1];
	}
	else if (visited[N - 1][M - 1][1] == 0) {
		cout << visited[N - 1][M - 1][0];
	}
	else {
		cout << min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]);
	}
	return 0;

}
