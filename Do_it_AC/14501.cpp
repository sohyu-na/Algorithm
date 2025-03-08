#include <iostream>
#include <vector>

    using namespace std;


    int main() {
        int N;
        cin >> N;

        vector<vector<int>> a(N + 1, vector<int>(2));

        for (int i = 1; i <= N; i++) {
            cin >> a[i][0] >> a[i][1];
        }

        vector<int> dp(N+2);
        dp[N + 1] = 0;
        for (int i = N; i >0; i--) {
            if (i + a[i][0] <= N+1) {
                dp[i] = max(a[i][1]+dp[i + a[i][0]],dp[i+1]);
            }
            else {
                dp[i] = dp[i + 1];
            }
        }
        cout << dp[1];
    }
