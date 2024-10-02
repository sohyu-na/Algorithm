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
    
    int n,k; cin >> n >> k;
    int DP[1001][1001];

    for (int i = 0; i <= n; i++) {
        DP[i][0] = 1;
        DP[i][1] = i;
        DP[i][i] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
            DP[i][j] = DP[i][j] % 10007;
        }
    }
    
    cout << DP[n][k];

    return 0;
}