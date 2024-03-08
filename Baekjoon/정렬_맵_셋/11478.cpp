#include <iostream>
#include <set>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str; cin >> str;
    set <string> s;
    for (int i = 0; i < str.length(); i++) {
        for (int j = 1; i+j <= str.length(); j++) {
            s.insert(str.substr(i,j));

        }
    }

    cout << s.size();
}
