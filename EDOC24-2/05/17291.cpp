#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;  cin >> n;

    int dp[21];
    int k[21];

    dp[1] = 1;
    k[1] = 1;
    dp[2] = 1+1;
    k[2] = 1;
    dp[3] = 1+1+2;
    k[3] = 2;
    dp[4] = 1 + 2 + 4 ;
    k[4] = 4;
    dp[5] = 1 + 2 + 4+ 7;
    k[5] = dp[4];
    //dp[6] = 4 + 7 + 14;
    //1-4,2,3-6 

    for (int i = 5; i <= 20; i++) {
        if (i % 2 == 0) {
            dp[i] = 2 * dp[i - 1] - k[i-3] - k[i-4];
        }
        else {
            dp[i] = 2 * dp[i - 1];
        }
        k[i] = dp[i - 1];
    }
    cout << dp[n];


    return 0;
}