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
    string input; cin >> input;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += input[i] - '0';
    }
    cout << sum;
    return 0;
}