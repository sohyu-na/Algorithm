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
    
    int r, c,w; cin >> r>>c>>w;
    r = r - c + 1;
    long long DP[31][31];//0~30

    for (int i = 1; i <= 30; i++) {
        DP[1][i] = 1;
        DP[i][1] = 1;
    }
    
    for (int i = 2; i <= 30; i++) {
        for (int j = 2; j <= 30; j++) {
            DP[i][j] = (DP[i - 1][j] +DP[i][j-1]);
        }
    }
    int sum = 0;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w-i ; j++) {
            sum += DP[r + i][c + j];
        }
    }

    cout << sum;
    return 0;
}