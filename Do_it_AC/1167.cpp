#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V;

vector<pair<int, int>> vv;
vector<vector<pair<int, int>>> v;

vector<bool> visited;

void dfs(int,int);
int total = 0;
int q;

int main() {
	cin >> V;

	v.resize(V + 1, vv);
	visited.resize(V + 1);

	int k;
	int n, w;
	for (int i = 0; i < V; i++){
		cin >> k;
		while (true) {
			cin >> n;
			if (n == -1) {
				break;
			}
			cin >> w;
			v[k].push_back(make_pair(n,w));
		}
	}
	//dfs 두번하기
	dfs(1,0);
	fill(visited.begin(), visited.end(), false);
	total = 0;
	dfs(q, 0); 
	cout << total;
}

void dfs(int t,int ans) {
	visited[t] = true;
	if (total < ans) {
		total = ans;
		q = t;
	}
	for (int i=0;i<v[t].size();i++){
		int k = v[t][i].first;
		if (!visited[k]) {
			dfs(k,ans + v[t][i].second);
		}
	}
}