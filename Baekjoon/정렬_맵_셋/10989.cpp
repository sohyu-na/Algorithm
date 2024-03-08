#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector <int> v(MAX+1);

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[a]++; //카운팅 
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << i << "\n";
        }
    }

    return 0;
}
