#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, l; cin >> n >> l;

    priority_queue <int, vector<int>, greater<>> q;
    priority_queue <int, vector<int>, greater<>> qS;
    deque <int> dq;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
        dq.push_back(x);
        if (i >= l) {
            while (!qS.empty() and q.top() == qS.top()) {
                q.pop(); qS.pop();
            }

            if (q.top() == dq.front()) {
                q.pop();
                while (!qS.empty() and q.top() == qS.top()) {
                    q.pop(); qS.pop();
                }
            }
            else {
                qS.push(dq.front());
            }

            dq.pop_front();
        }
        cout << q.top() << " ";
    }
    return 0;
}
/* 3 5 6 7
q  2 3 5 5 6 6 7
dq 5 2 6
   2 2 1 1 1 2 2 2 3 3 2 2
   
*/