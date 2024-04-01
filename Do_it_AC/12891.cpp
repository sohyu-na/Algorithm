#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int s, p; cin >> s >> p;
    string dna; cin >> dna;
    int a, c, g, t; cin >> a >> c >> g >> t;

    map <char, int> m;
    int k = 0; int cnt = 0;
    for (int i = 0; i < p; i++) {
        m[dna[i]]++;
    }
    while (k+p<=s) {
        if (m['A'] >= a and m['C'] >= c and m['G'] >= g and m['T'] >= t) {
            cnt++;
        }
        m[dna[k]]--;
        m[dna[k + p]]++;
        k++;
    }
    cout << cnt;
    return 0;
}
