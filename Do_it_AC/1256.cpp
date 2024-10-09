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

    int n, m, k; cin >> n >> m >> k;
    
    int dp[201][201];//문자열의 수,z의 수

    for (int i = 0; i <= n+m; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                //k 범위 초과시
                if (dp[i][j] > 1000000000) {
                    dp[i][j] = 1000000001;
                }
            }
        }
    }

    if (dp[n + m][m] < k) {
        cout << "-1";
    }
    else {
        while(n+m) {
            if (k > dp[n + m - 1][m] and m>0) {//z
                cout << "z";
                k -= dp[n+m-1][m];
                m--;
            }
            else {
                cout << "a";
                n--;
            }
        }
    }

    
    return 0;
}