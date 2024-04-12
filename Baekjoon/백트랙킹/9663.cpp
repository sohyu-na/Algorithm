#include <iostream>
#include <queue>
#include <vector>
#include <string>


using namespace std;
const int SIZE = 15;

int n, ans;
int queen_loc[SIZE];

bool possible_loc(int c) {
    for (int i = 0; i < c; i++) {
        if (queen_loc[i] == queen_loc[c] 
            or abs(i-c)==abs(queen_loc[i]-queen_loc[c])) {
            return false;
        }
    }
    return true;
}
void backtrack(int c) {
    if (c == n) {
        ans++;
        return;
    }
    for (int r = 0; r < n; r++) {
        queen_loc[c] = r;
        if (possible_loc(c)) {
            backtrack(c + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    backtrack(0);

    cout << ans;

    return 0;
}