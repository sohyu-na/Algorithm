#include <iostream>
#include <set>

using namespace std;

const int MAX = 10000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    set <int> s;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }

    cin >> n;
    int s_s;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s_s = s.size();
        s.insert(a);
        if (s_s == s.size()) {
            cout << "1 ";
        }
        else {
            s.erase(a);
            cout << "0 ";
        }
        
    }

    return 0;
}
