#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
vector <vector<int>> v;
vector <bool> visited;

void calcu(int k) {
    visited[k] = true;

    for (int i : v[k]) {
        if (!visited[i]) {
            calcu(i);
        }
    }
    return;
}
  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    //vector<int> vv;
    //v.assign(n + 1,vv);
    v.resize(n + 1);
    visited.assign(n + 1, false);

    //입력
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    //연산
    int cnt = 0;
    for (int i = 1; i < n + 1; i++) {//방문하지 않은 노드 찾기
        if (!visited[i]) {
            cnt++;
            calcu(i);
        }
    }
    //출력
    cout << cnt;
    return 0;
}