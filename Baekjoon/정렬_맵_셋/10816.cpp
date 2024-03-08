#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    map <int, int> m;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        m[a]++;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cout << m[a] << " ";
        
    }
    return 0;
}
