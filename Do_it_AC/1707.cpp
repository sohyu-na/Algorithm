#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> v;
vector<int> check;//0 과 1로 분류
int n, m;
bool dfs(int t) {
	for (int i: v[t]) {
		if (check[i]!=-1) {//방문 후 
			cout <<i<<";" << check[i] << "/\n";
			if (check[i]!=(check[t] + 1) % 2) {//반대쪽에 있는지 확인 
				return false;
			}
		}
		else {//방문 전
			cout << t << " ," << i << "\n";
			check[i] = (check[t] + 1) % 2;//반대쪽으로 분류
			bool b = dfs(i); 
			if (!b) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int k; cin >> k;
	for (int i = 0; i < k; i++){
		cin >> n >> m;
		int a, b;
		v.clear(); check.clear();
		v.resize(n+1); check.resize(n + 1,-1);
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		//이분그래프 검사 = cycle여부 검사 
		//그래프가 이어져있다는 보장이 없으므로 각 DFS 실행
		bool c = true; 
		check[1] = 1;
		for (int j = 1; j < n + 1; j++) {
			if (j == 1) { //노드 1부터 dfs 실행 
				c = dfs(1);
			}
			else if(check[j] == -1) {//탐색 안되어있으면
				c=dfs(j); //다시 해당 노드부터 dfs
			}
			if (!c) {
				cout << "NO\n";
				break;
			}
		}
		if (c) {
			cout << "YES\n";
		}
	}
}