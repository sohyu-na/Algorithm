#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n ;
    vector <int> va(n);
    vector <int> vb(n);
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vb[i];
    }

    while (n !=0) {
        if (va == vb) {
            cout << "1";
            return 0;
        }
        int max = 0, max_idx=0;
        for (int i = 0; i < n; i++) {
            if (max < va[i]) {
                max = va[i];
                max_idx = i;
            }
        }
        if (max_idx != n - 1) {
            swap(va[max_idx], va[n - 1]);
        }
        n--;
    }
    cout << "0";
    return 0;
}