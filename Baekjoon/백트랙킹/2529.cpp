#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
int n;
string min_n = "9876543210";
string max_n = "0123456789";

vector <char> bk;
vector <int> choose;
vector <bool> is_used(10, false);

string chooseToString() {
    string num = "";

    for (int i = 0; i < choose.size(); i++) {
        num += to_string(choose[i]);
    }
    return num;
}
void updateAns() {
    string num = chooseToString();
    max_n = max(max_n, num);
    min_n = min(min_n, num);
}
void findMinMax(int idx) {
    if (idx == n + 1) {
        updateAns();
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (is_used[i]) {
            continue;
        }
        choose.push_back(i);
        is_used[i] = true;

        if (idx == 0
            or (bk[idx-1] == '<' and choose[choose.size() - 2] < i)
            or (bk[idx-1] == '>' and choose[choose.size() - 2] > i)) {
            findMinMax(idx + 1);
        }

        is_used[i] = false;
        choose.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    bk.assign(n, '<');
    for (int i = 0; i < n; i++) {
        cin >> bk[i];
    }
    min_n = min_n.substr(0, n + 1);
    max_n = max_n.substr(0, n + 1);

    findMinMax(0);
    cout << max_n << "\n" << min_n;

    return 0;
}