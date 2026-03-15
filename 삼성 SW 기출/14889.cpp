#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> v;
int n;
int minV = INT_MAX;

int sumTeam(bool start[21], bool link[21]) {
    int sumS = 0;
    for (int i = 0; i < n; i++) {
        if (start[i]) {
            for (int j = i + 1; j < n; j++) {
                if (start[j]) {
                    sumS += (v[i][j] + v[j][i]);
                }
            }
        }
    }

    int sumL = 0;
    for (int i = 0; i < n; i++) {
        if (link[i]) {
            for (int j = i + 1; j < n; j++) {
                if (link[j]) {
                    sumL += (v[i][j] + v[j][i]);
                }
            }
        }
    }

    return abs(sumL - sumS);
}

void calc(int i, bool start[21], bool link[21], int startC, int linkC) {
    if (startC > n / 2 || linkC > n / 2) return;

    if (i == n) {
        if (startC == n / 2 && linkC == n / 2) {
            minV = min(minV, sumTeam(start, link));
        }
        return;
    }

    start[i] = true;
    calc(i + 1, start, link, startC + 1, linkC);
    start[i] = false;

    link[i] = true;
    calc(i + 1, start, link, startC, linkC + 1);
    link[i] = false;
}

int main() {
    cin >> n;
    v.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    bool start[21] = { false };
    bool link[21] = { false };

    start[0] = true;              // 대칭 제거
    calc(1, start, link, 1, 0);

    cout << minV;
}