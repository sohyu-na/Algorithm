#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculate(int i) {
    int sum = i;
    while (i % 10) {
        sum += i % 10;
        i /=  10;
    }
    
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        if (n == calculate(i)) {
            cout << i;
            return 0;
        }
    }
    cout << "0";
    return 0;
}
