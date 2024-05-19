#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 10001;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n; cin >> n;
    int count[MAX] = { 0 };

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        count[num]++;
    }

    //출력
    for (int i = 0; i < MAX; i++) {
        if (count[i] != 0) {
            while (count[i]--) {
                cout << i << "\n";
            }
        }
    }
    
    return 0;
}