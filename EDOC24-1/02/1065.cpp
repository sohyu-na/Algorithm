#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int cnt = 0;
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        if (i < 100) {
            cnt++;
        }
        else {
            a = i % 10;
            b = (i % 100)/10;
            c = i / 100;
            if (c - b == b - a) {
                cnt++;
            }
        }
        
    }
    cout << cnt;
    return 0;
    
}


