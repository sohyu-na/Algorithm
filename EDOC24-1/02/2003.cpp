#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    vector <int> v(n + 1); v[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v[i] = v[i - 1] + x;
    }
    //0 1 2 3 4
    int i = 0; int j = 1;
    int cnt = 0;
    while (true) {
        if (i == n) {
            break;
        }
        if (v[j] - v[i] == m) {
            cnt++; 
        }
        if (j != n) {
            j++;
        }
        else {
            i++; j = i + 1;
        }
    }
    cout << cnt;

    
    return 0;
}
/* 3 5 
q  2 3 3 5 6 7
dq 6 2 3 7
   2 2 1 1 1 2 2 
*/