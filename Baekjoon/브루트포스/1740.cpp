#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

long long madePow(long long n, int t) {
    long long sum = 1;
    for (int i = 0; i < t; i++) {
        sum *= n;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long n; cin >> n;

    long long sum = 0;
    for (int i = 0; i < 64; i++) {
        if (n & (long long)1 << i) {
            sum += madePow(3, i);
        }
    }
    cout << sum;
    return 0;
}
