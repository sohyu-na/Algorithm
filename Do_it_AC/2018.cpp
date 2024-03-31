#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int cnt = 0; int k;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            k = i / 2;
            if (n % i == k and n/i>=k) {
                cnt++;
            }
        }
        else {
            k = i / 2 +1;
            if (n % i == 0 and n/i>=k) {
                cnt++;
            }
        }
    }
    cout << cnt;
    
    return 0;
}
