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
    
    int n; cin >> n;

    //nxn 행렬 생성 및 입력
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    
    //점화식 -> 경로 존재 여부 업데이트 
    for (int k = 0; k < n; k++) {
        for (int s = 0; s < n; s++) {
            for (int e = 0; e < n; e++) {
                if (d[s][k] == 1 and d[k][e] == 1) {
                    d[s][e] = 1;
                }
            }
        }
    }

    //출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
             cout << d[i][j] << " ";
        }
        cout << "\n";
    }
   
    return 0;
}