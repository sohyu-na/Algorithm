#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m; cin >> m;
    int cr[51];
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> cr[i];//색상별 조약돌 수
        sum += cr[i];
    }
    int k; cin >> k;

    double und = 1;
    for (int i = 0; i < k; i++) {
        und *= (sum - i);
    }

    double up = 0;
    for (int i = 0; i < m; i++) {
        double upp = 1;
        if (cr[i] >= k) {
            for (int j = 0; j < k; j++) {
                upp *= (cr[i] - j);
            }
            up += upp;
        }
        
    }
    
    cout << setprecision(16)<< up/und;
    return 0;
}