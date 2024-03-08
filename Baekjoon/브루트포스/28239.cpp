#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 60;

pair <int, int> getPair(ll m) {
    int x, y;
    //m이 제곱수인 경우 
    //x==y 
    //m = 2^i -> x=y=i-1
    for (ll i = 1; i < MAX; i++) {
        if (m == ((ll)1 << i)) {
            return { i - 1,i - 1 };
        }
    }
    //m이 제곱수가 아닌 경우 
    for (x = 0; x < MAX; x++) {
        if (m & ((ll)1 << x)) {
            m -= (ll)1 << x;
            break;
        }
    }
    for (y = x + 1; y < MAX; y++) {
        if (m & ((ll)1 << y)) {
            break;
        }
    }
    return { x,y };
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    ll a;
    pair <int, int> p;
    while(n--){
        cin >> a;
        p =getPair(a);
        cout << p.first << " " << p. second << "\n";
    }

    return 0;
}
