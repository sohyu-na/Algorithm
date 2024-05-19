#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m; cin >> n >> m;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int num,score;
    int max_num=0, max_score=0;
    char c;
    for (int i = 0; i < m; i++) {
        cin >> num;
        score = 0;
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == 'O') {
                score += v[j];
            }
        }
       // cout << "[[" << score << "]]";
        if (max_score < score) {
            max_score = score;
            max_num = num;
        }
        else if (max_score == score) {
            if (max_num == 0) {
                max_num = num;
            }
            max_num = (max_num > num) ? num : max_num;
        }
    }

    cout << max_num << " " << max_score;
    
    return 0;
}