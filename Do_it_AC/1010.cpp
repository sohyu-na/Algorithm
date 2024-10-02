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
    
    int DP[30][30];//0~29

    for (int i = 1; i < 30; i++) {
        DP[i][1] = i;
        DP[i][i] = 1;
    }
    
    for (int i =3; i < 30; i++) {
        for (int j = 2; j < i; j++) {
            DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
        }
    }

    int t; cin >> t;
    int n, m;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        cout << DP[m][n]<<"\n";
    }

    return 0;
}