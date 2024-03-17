#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    deque <int> q;
    for (int i = 1; i <=n; i++) {
        q.push_back(i);
    }
    while (q.size() != 1) {
        q.pop_front();
        int k = q.front();
        q.pop_front();
        q.push_back(k);
    }

    cout << q.front();
   
    return 0;
}


