#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int x;
    priority_queue <int,vector<int>, greater<>> q;
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }
    while (!q.empty()) {
        int s = q.size();
        int t = q.top();
        if (s * t > max) {
            max = s * t;
        }
        q.pop();
    }
    
    cout << max;
    return 0;
}