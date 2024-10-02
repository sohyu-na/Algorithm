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
    
    int DP[15][15]; //0~14

    for (int i = 1; i <= 14; i++) {
        DP[0][i] = i;
    }
    
    int sum = 0;
    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) {
            sum += DP[i - 1][j];
            DP[i][j] = sum;
        }
        sum = 0;
    }
    
    int t; cin >> t;
    int a, b;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << DP[a][b] << "\n";
    }

    return 0;
}