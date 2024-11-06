#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    int dp[101][10];

    dp[1][0] = 0;
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][1]) % 1000000000;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 1000000000;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % 1000000000;
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % 1000000000;
        dp[i][4] = (dp[i - 1][3] + dp[i - 1][5]) % 1000000000;
        dp[i][5] = (dp[i - 1][4] + dp[i - 1][6]) % 1000000000;
        dp[i][6] = (dp[i - 1][5] + dp[i - 1][7]) % 1000000000;
        dp[i][7] = (dp[i - 1][6] + dp[i - 1][8]) % 1000000000;
        dp[i][8] = (dp[i - 1][7] + dp[i - 1][9]) % 1000000000;
        dp[i][9] = (dp[i - 1][8]) % 1000000000;
    }
    
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum =(sum+ dp[n][i])%1000000000;
    }
    
    cout << sum;
    return 0;
}