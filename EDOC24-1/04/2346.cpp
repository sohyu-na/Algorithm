#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int x;
    deque <int> d;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        d.push_back(i);
        cin >> v[i];
    }
    n--;
    while (n--) {
        cout << d.front()<<" ";
        x = v[d.front()];
        d.pop_front();
        if (x > 0) {
            x--;
            while (x--) {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        else {
            while (x++) {
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }
    cout << d.front();
    return 0;
}