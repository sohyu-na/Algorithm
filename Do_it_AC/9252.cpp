#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
string a, b;
int dp[1001][1001] = { 0 };
vector<char> v;

void txt(int i, int j) {
    if (i == 0 or j == 0) {
        return;
    }
    if (a[i - 1] == b[j - 1]) {
        v.push_back(a[i - 1]);
        txt(i - 1, j - 1);
    }
    else {   
        if (dp[i - 1][j] > dp[i][j - 1]) {
            txt(i - 1, j);
        }
        else {
            txt(i, j - 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;

    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    cout << dp[a.length()][b.length()] << "\n";

    txt(a.length(), b.length());
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }

    return 0;
}