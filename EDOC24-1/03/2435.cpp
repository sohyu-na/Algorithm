#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k; cin >> n >>k;
    int x, sum = 0;
    vector <int> v(n+1,0);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
        v[i] = sum;
    }
    int max = (-100)*k; //max를 0으로 잡는 게 최소값이 아님 *실수 xx
    for (int i = 0; i <= n-k; i++) {
        if (v[i + k] - v[i] > max) {
            max = v[i + k] - v[i];
        }
    }
    cout << max;

    return 0;
}