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
    
    int n,m; cin >> n >> m;

    //nxn 행렬 생성 및 입력 
    vector<vector<long long>> d(n+1, vector<long long>(n+1,INT_MAX));
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    
    //점화식 -> 케빈 베이컨 수 업데이트 
    for (int k = 1; k <= n; k++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                d[s][e] = min(d[s][e], d[s][k] + d[k][e]);
            }
        }
    }

    //케빈 베이컨 수 계산 
    int min_value = INT_MAX;
    int min_num=0;
    int sum=0;
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += d[i][j];
        }
        if (sum < min_value) {
            min_value = sum;
            min_num = i;
        }
    }

    cout << min_num;
   
    return 0;
}