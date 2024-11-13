#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
long long dp[101][101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, R;
    cin >> N >> L >> R;

    dp[1][1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int l = 1; l <= L; l++) {
            for (int r = 1; r <= R; r++) {
                //가장 큰 빌딩을 기준으로 따지면 복잡하므로 
                //i-1번째 빌딩들의 길이를 +1해서 생각하고 가장 작은 길이 1 빌딩을 왼,중,오 배치 3가지로 나눠 생각
                dp[i][l][r] = (dp[i - 1][l - 1][r] + dp[i - 1][l][r - 1] + dp[i - 1][l][r] * (i - 2)) % MOD;
            }
        }
    }

    cout << dp[N][L][R] << "\n";

    return 0;
}