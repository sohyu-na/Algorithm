#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long unsigned int n; cin >> n;
    int x;
    queue <int> s;
    while (true) {
        cin >> x;
        if (x == -1) {
            break;
        }
        else if (x == 0) {
            s.pop();
        }
        else if (s.size() < n) {
           s.push(x);
        }
    }
    if (s.empty()) {
        cout << "empty";
    }
    while (!s.empty()) {
        cout << s.front() << " ";
        s.pop();
    }
    return 0;
}