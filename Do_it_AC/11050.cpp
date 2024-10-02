#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,k; cin >> n >> k;
    float ans = 1;
    for (int i = 0; i < k; i++) {
        ans = ans * (n - i)/(k-i);

    }
    
    cout << ans;

    return 0;
}