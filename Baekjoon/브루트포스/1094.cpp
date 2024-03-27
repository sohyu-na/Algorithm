#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;



int main()
{
    int n; cin >> n;
    vector <int> v(7);
    for (int i = 0; i < 8; i++) {
        v[i] = pow(2, i);
    }
    int cnt = 0;
    for (int i = 7; i >= 0; i--) {
        if (n >= v[i]) {
            n = n - v[i];
            cnt++;
        }
    }
    
    cout << cnt;
}
