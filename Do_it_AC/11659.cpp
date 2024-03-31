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
    vector <int> v(n+1);
    int x;
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v[i] = v[i - 1] + x;
    }
    int i, j;
    while(m--) {
        cin >> i >> j;
        cout << v[j] - v[i - 1]<<"\n";
    }
    
    return 0;
}
