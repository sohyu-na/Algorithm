#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector <float> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    float high = v[n - 1];
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum +(v[i] / high * 100);
    }
    //50 75 100
    cout << sum/n;
    return 0;
}


