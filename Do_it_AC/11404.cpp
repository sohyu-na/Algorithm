#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;

    //nxn 행렬 생성 및 초기화 
    vector<vector<int>> d(n+1, vector<int>(n+1, 100001));
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }

    //그래프 -> 행렬 업데이트 
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (d[a][b] > c) { //경로가 하나가 아닐 수 있음 
            d[a][b] = c; 
        }
    }
    
    //점화식 -> 최단 경로 업데이트 
    for (int k = 1; k <= n; k++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                d[s][e] = min(d[s][e], d[s][k] + d[k][e]);
            }
        }
    }

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == 100001) {
                cout << "0 ";
            }
            else {
                cout << d[i][j] << " ";
            }
        }
        cout << "\n";
    }
   
    return 0;
}