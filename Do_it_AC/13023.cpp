#include <iostream>
#include <vector>

using namespace std;
int N, M;
//그래프 표현
static vector <vector <int>> v;
static vector <bool> visited;
static bool arrive;
void dfs(int, int);

int main() {
    cin >> N >> M;
    v.resize(N);
    visited.resize(N, false);
    //그래프 입력
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        dfs(i, 1);
        if (arrive) {
            break;
        }
    }
    if (arrive) {
        cout << "1";
    }
    else {
        cout << "0";
    }
    
        
}
void dfs(int a,int cnt) {
    if (cnt == 5 or arrive) {
        arrive = true;
        return;
    }
    visited[a] = true;
    //그래프 탐색
    for (int i : v[a]) {
        if (!visited[i]) {
            dfs(i, cnt+1);
        }
    }
    visited[a] = false;
    
}