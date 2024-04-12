#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
const int MAX = 8;
int n, m;
bool is_used[MAX + 1];
int sequence[MAX];

void print() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void backtracking(int idx) {
    if (idx == m) {
        print();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (is_used[i]) {
            continue;
        }
        sequence[idx] = i;
        is_used[i] = true;

        backtracking(idx + 1);
        is_used[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n>>m;

    backtracking(0);

    return 0;
}