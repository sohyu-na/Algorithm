#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k; cin >> n>>k;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<>());
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (k >= v[i]) {
            m += k / v[i];
            k = k % v[i];
            if (k == 0) {
                break;
            }
        }
    }
    cout << m;
    return 0;
}


