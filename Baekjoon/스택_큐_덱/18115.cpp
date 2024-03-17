#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    deque <int> q;
    deque <int> qq;

    for (int i = 0; i < n; i++) {
        q.push_back(i);
    }
    int tk;
    for (int i = n; i > 0; i--) {
        int x; cin >> x;
        if (x == 1) {
            qq.push_back(q.front());
            q.pop_front();
        }
        else if (x == 2) {
            tk =q.front(); q.pop_front();
            qq.push_back(q.front()); q.pop_front();
            q.push_front(tk);
        }
        else if (x == 3) {
            qq.push_back(q.back());
            q.pop_back();
        }
    }

    vector <int> v(n);
    for(int i=n;i>0;i--){
        v[qq.front()] = i;
        qq.pop_front();
    }
    

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}


