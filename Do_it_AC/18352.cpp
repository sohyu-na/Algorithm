#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k, x; cin >> n>>m>>k>>x;

    //가중치 없는 인접 리스트 구현
    vector <vector<int>> v(n+1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    //최단 거리 저장 배열 
    vector <int> dis(n+1,-1);
    queue <int> q;

    dis[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int t = q.front();q.pop();
        for (int i : v[t]) {
            if (dis[i] == -1) {
                dis[i] = dis[t] + 1;
                q.push(i);
            }
        }
    }

    bool check = false;
    for (int i = 1; i < n+1; i++) {
        if (dis[i] == k) {
            check = true;
            cout << i << "\n";
        }
    }
    if (!check) {
        cout << "-1";
    }

    return 0;
}