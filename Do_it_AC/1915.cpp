#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

int n, m;
int dp[1001][1001];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //int n, l.r; cin >> n >> l >> r;

    cin >> n >> m;
    long max = 0;

    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < m; j++) {
            dp[i][j] = temp[j]-48;

            if (dp[i][j] == 1 and i > 0 and j > 0) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            if (max < dp[i][j]) {
                max = dp[i][j];
            }
        }
    }    
    cout << max*max;
    
    return 0;
}