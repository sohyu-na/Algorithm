#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m; cin >> n>>m;
    vector<vector<int>> v(n+1, vector<int>(n+1));

    int x;  
    v[0][n] = 0;
    for (int i=1; i <= n; i++) {
        int sum = 0;
        v[i][0] = 0;
        for (int j = 1; j <= n; j++) {
            cin >> x;
            sum += x;
            v[i][j] = sum;;
        }
    }

    int i, j;
    int a, b;
    while(m--) {
        cin >> i >> j>>a>>b;
        int sum = 0;
        for (int k = i; k <= a; k++) {
            sum += v[k][b] - v[k][j-1];
        }
        cout << sum << "\n";
    }
    return 0;
}
