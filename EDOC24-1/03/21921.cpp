#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x; cin >> n >> x;
    vector <int> v(n); int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i < x) {
            sum += v[i];
        }
    }
    int max = sum;
    int i = 0; int cnt = 1; bool check = true;
    while (i+x<=n-1) {
        sum += (v[i + x] - v[i]);
        if (sum > max) {
            max = sum;
            cnt = 1;
        }
        else if (sum == max) {
            cnt++;
        }
        
        i++;
    }

    if (sum == 0) {
        cout << "SAD";
    }
    else {
        cout << max << "\n" << cnt;
    }

    
    return 0;
}
