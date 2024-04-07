#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>(m+1));

    for (int i = 1; i <= n; i++) {
        int x, sum = 0;
        v[i][0] = 0;
        for (int j = 1; j <= m; j++) {
            cin >> x;
            sum += x;
            v[i][j]=sum;
        }
    }
    // 1 3 7
    int k; cin >> k;
    int i, j, x, y;
    while(k--) {
        cin >> i >> j >> x >> y;
        int sum = 0;
        for(int t=i;t<=x;t++){
            sum += v[t][y] - v[t][j - 1];
        }
        cout << sum<<"\n";
    }
    return 0;
}