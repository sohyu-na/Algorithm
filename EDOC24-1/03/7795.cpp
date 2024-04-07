#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> vn(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> vn[i];
        }
        sort(vn.begin(), vn.end());

        vector<int> vm(m, 0);
        for (int i = 0; i < m; i++) {
            cin >> vm[i];
        }
        sort(vm.begin(), vm.end());

        int cnt = 0;
        int i = 0; int j = 0;
        while (true) {
            if (j == m or i==n) {
                break;
            }
            if (vm[j] < vn[i]) {
                cnt = cnt + (n - i);
                j++;
            }
            else {
                i++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}