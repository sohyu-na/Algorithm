#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n ;
    vector <long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n-1; i++) {
        v[i]=v[i+1]-v[i];
    }
    long long sum = 0;
    for (int i = 0; i < n-1; i++) {
        sum += v[i] * (n - 1 - i)*(i+1);
    }
    cout << 2*sum <<"\n";

    return 0;
}