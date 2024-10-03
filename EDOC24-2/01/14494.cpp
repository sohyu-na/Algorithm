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

    long long DP[1001][1001];//0~1000

    for (int i = 1; i <= 1000; i++) {
        DP[1][i] = 1;
        DP[i][1] = 1;
    }
    
    for (int i = 2; i <= 1000; i++) {
        for (int j = 2; j <= 1000; j++) {
            DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]+DP[i][j-1])%1000000007;
        }
    }
    
    cout << DP[n][m];

    return 0;
}