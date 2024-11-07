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

    int dp[1001];

    //0-sk, 1-cy
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;
    dp[5] = 0;

    if (n % 2 == 0) {
        cout << "CY";
    }
    else {
        cout << "SK";
    }


    
    return 0;
}