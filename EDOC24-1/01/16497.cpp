#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int x, y;
    multimap <int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        m.insert(make_pair(x, y));
    }
    int k; cin >> k;
    vector <int> v(k,0);
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        bool check = true;
        for (int i = 0; i < k; i++) {
            if (v[i] <= iter->first) {
                v[i] = iter->second;
                check = false;  break;
            }
        }
        if (check) {
            cout << "0"; return 0;
        }
    }
    cout << "1";

    return 0;
}


