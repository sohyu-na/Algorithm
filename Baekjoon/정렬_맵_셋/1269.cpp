#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;
    int a;
    set <int> s;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (s.end() != s.find(a)) {
            sum++;
        }
    }

    cout << n + m - sum - sum;
}
