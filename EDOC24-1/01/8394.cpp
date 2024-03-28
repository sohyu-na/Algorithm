#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector <int> dp(n+1);
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2])%10;
    }
    cout << dp[n];
    
    return 0;

}

