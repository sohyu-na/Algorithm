#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m; cin >> n>>m;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    int i = 0; int j = 1;
    while (i != n-1) {
        if (v[i] + v[j] == m) {
            cnt++; i++; j = i+1;
        }
        else if(j!=n-1) {
            j++;
        }
        else {
            i++; j = i + 1;
        }
    }
    cout << cnt;
    return 0;
}
