#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
vector <bool> check_dfs;
vector <bool> check_bfs;

void dfs(vector<vector<int>>& vv, int n,int v,deque <int> &s) {
    s.push_back(v);
    check_dfs[v] = true;
    for (int i = 1; i <= n; i++) {
        if (vv[v][i] and !check_dfs[i]) {
            dfs(vv, n, i, s);
        }
    }
    return;
}

void bfs(vector<vector<int>>& vv, int n, int v, deque <int>& s) {
    queue <int> q;
    q.push(v);  s.push_back(v);
    check_bfs[v] = true;

    while (!q.empty()) {
        v = q.front(); 
        for (int i = 1; i <= n; i++) {
            if (vv[v][i] and !check_bfs[i]) {
                q.push(i); s.push_back(i);
                check_bfs[i] = true;
            }
        }
        q.pop(); 
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m,v; cin >> n>>m>>v;

    vector<vector<int>> vv(n+1, vector<int>(n+1,0));

    int x, y;
    while (m--) {
        cin >> x >> y;
        vv[x][y] = 1;
        vv[y][x] = 1;
    }
    deque <int> s; 
    check_dfs.assign(n + 1,false);
    dfs(vv,n,v,s);
    while (!s.empty()) {
        cout << s.front() << " ";
        s.pop_front();
    }
    cout << "\n";
    check_bfs.assign(n + 1, false);
    bfs(vv, n, v, s);
    while (!s.empty()) {
        cout << s.front() << " ";
        s.pop_front();
    }
    return 0;
}