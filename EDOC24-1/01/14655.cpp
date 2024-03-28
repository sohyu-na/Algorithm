#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int max = 0; int in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        if (in < 0) {
            max -= in;
        }
        else {
            max += in;
        }
    }
    int min = 0;
    for (int i = 0; i < n; i++) {
        cin >> in;
        if (in < 0) {
            min += in;
        }
        else {
            min -= in;
        }
    }
    cout << max - min;
    return 0;

}

