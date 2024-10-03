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
    
    int n, m; cin >> n>>m;

    long long DP[31][31];//0~30

    for (int i = 1; i <= 30; i++) {
        DP[i][i] = 1;//1개씩
        DP[1][i] = 1;//과일 종류 1개 
    }
    
    for (int i = 2; i <= 30; i++) {
        for (int j = i+1; j <= 30 ; j++) {
            DP[i][j] = (DP[i - 1][j-1] +DP[i][j-1]);
        }
    }

    cout << DP[n][m];
    return 0;
}