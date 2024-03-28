#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

void cooking(int i,int n,int s, int t, vector<ci>& v, int &bet) {
    if (i == n) {
        if (s!=1 and t!=0 and abs(s - t) < bet) {
            bet = abs(s - t);
        }
        return;
    }
    cooking(i + 1, n, s, t, v, bet);
    s *= v[i].first;
    t += v[i].second;
    cooking(i + 1, n, s, t, v, bet); 

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ci> v(n);

    int s = 1; int t = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    int bet = abs(v[0].first - v[0].second);
    cooking(0,n,s,t,v, bet);

    cout << bet;
    return 0;
}
