#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
static vector <vector <int>> v;
static vector <bool> visited;
static vector <int> ans;
static deque <int> deq;

void dfs(int);
void bfs(int);

int main() {
    int N, M,V;
    cin >> N >> M >> V;
    v.resize(N+1);
    visited.resize(N+1, false);
    //그래프 입력
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a); 
    }
    for (int i = 1; i <= N; i++) {
        //정렬
        sort(v[i].begin(), v[i].end());
    }
    dfs(V);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    fill(visited.begin(), visited.end(),false);
    ans.clear();
    bfs(V);
    for (int i : ans) {
        cout << i << " ";
    }
        
}
void dfs(int a) {
    visited[a] = true;
    ans.push_back(a);
    //그래프 탐색
    for (int i : v[a]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    return;
}
void bfs(int a) {
    visited[a] = true;
    deq.push_back(a);
    while (!deq.empty()) {
        int t = deq.front();
        ans.push_back(t);
        deq.pop_front();
        for (int i : v[t]) {
            if (!visited[i]) {
                deq.push_back(i);
                visited[i] = true;
            }
        }
    }
    return;
}