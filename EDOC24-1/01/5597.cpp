#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    set <int> s;
    for (int i = 1; i < 31; i++) {
        s.insert(i);
    }
    int x;
    for (int i = 0; i < 28; i++) {
        cin >> x;
        s.erase(x);
    }

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << "\n";
    }
    
    return 0;
}


